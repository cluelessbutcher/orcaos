#include "heap.h"
#include "kernel.h"
#include "status.h"
#include "memory/memory.h"
#include <stdbool.h>

static bool heap_validate_alignment(void* ptr) {
    return (((uint32_t)ptr % ORCAOS_HEAP_BLOCK_SIZE) == 0);
}

static int heap_validate_table(void* ptr, void* end, struct heap_table* table) {
    size_t table_size = (size_t)((char*)end - (char*)ptr); 
    size_t total_blocks = table_size / ORCAOS_HEAP_BLOCK_SIZE;
    
    if (table->total != total_blocks) {
        return -EINVARG;
    }
    return 0;
}

static uint32_t heap_align_value_to_upper(uint32_t val) {
    if ((val % ORCAOS_HEAP_BLOCK_SIZE) == 0) {
        return val;
    }
    return (val - (val % ORCAOS_HEAP_BLOCK_SIZE)) + ORCAOS_HEAP_BLOCK_SIZE;
}

static int heap_get_entry_type(HEAP_BLOCK_TABLE_ENTRY entry) {
    return entry & 0x0f;
}

static void* heap_block_to_address(struct heap* heap, int block) {
    return (char*)heap->saddr + (block * ORCAOS_HEAP_BLOCK_SIZE);
}

static int heap_address_to_block(struct heap* heap, void* address) {
    return (int)((char*)address - (char*)heap->saddr) / ORCAOS_HEAP_BLOCK_SIZE;
}

static int heap_get_start_block(struct heap* heap, uint32_t total_blocks) {
    struct heap_table* table = heap->table;
    uint32_t bc = 0;
    int bs = -1;

    for (size_t i = 0; i < table->total; i++) {
        if (heap_get_entry_type(table->entries[i]) != HEAP_BLOCK_TABLE_ENTRY_FREE) {
            bc = 0;
            bs = -1;
            continue;
        }

        if (bs == -1) {
            bs = i;
        }
        bc++;

        if (bc == total_blocks) {
            break;
        }
    }

    if (bs == -1) {
        return -ENOMEM;
    }
    return bs;
}

static void heap_mark_blocks_taken(struct heap* heap, int start_block, uint32_t total_blocks) {
    int end_block = (start_block + total_blocks) - 1;

    for (int i = start_block; i <= end_block; i++) {
        HEAP_BLOCK_TABLE_ENTRY entry = HEAP_BLOCK_TABLE_ENTRY_TAKEN;
        
        if (i == start_block) {
            entry |= HEAP_BLOCK_IS_FIRST;
        }
        
        if (i < end_block) {
            entry |= HEAP_BLOCK_HAS_NEXT;
        }
        
        heap->table->entries[i] = entry;
    }
}

static void heap_mark_blocks_free(struct heap* heap, int starting_block) {
    struct heap_table* table = heap->table;
    for (int i = starting_block; i < (int)table->total; i++) {
        HEAP_BLOCK_TABLE_ENTRY entry = table->entries[i];
        table->entries[i] = HEAP_BLOCK_TABLE_ENTRY_FREE;
        
        if (!(entry & HEAP_BLOCK_HAS_NEXT)) {
            break;
        }
    }
}

static void* heap_malloc_blocks(struct heap* heap, uint32_t total_blocks) {
    int start_block = heap_get_start_block(heap, total_blocks);
    if (start_block < 0) {
        return NULL;
    }
    
    void* address = heap_block_to_address(heap, start_block);
    heap_mark_blocks_taken(heap, start_block, total_blocks);

    return address;
}

int heap_create(struct heap* heap, void* ptr, void* end, struct heap_table* table) {
    if (!heap_validate_alignment(ptr) || !heap_validate_alignment(end)) {
        return -EINVARG;
    }

    memset(heap, 0, sizeof(struct heap));
    heap->saddr = ptr;
    heap->table = table;

    int res = heap_validate_table(ptr, end, table);
    if (res < 0) {
        return res;
    }

    size_t table_size = sizeof(HEAP_BLOCK_TABLE_ENTRY) * table->total;
    memset(table->entries, HEAP_BLOCK_TABLE_ENTRY_FREE, table_size);

    return 0;
}

void* heap_malloc(struct heap* heap, size_t size) {
    if (size == 0) {
        return NULL;
    }

    size_t aligned_size = heap_align_value_to_upper(size);
    uint32_t total_blocks = aligned_size / ORCAOS_HEAP_BLOCK_SIZE;

    return heap_malloc_blocks(heap, total_blocks);
}

void heap_free(struct heap* heap, void* ptr) {
    if (!ptr) {
        return;
    }
    
    int starting_block = heap_address_to_block(heap, ptr);
    heap_mark_blocks_free(heap, starting_block);
}
