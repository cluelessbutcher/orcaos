#pragma once

#include "config.h"
#include "task.h"
#include <stdint.h>

#define PROCESS_FILETYPE_ELF 0
#define PROCESS_FILETYPE_BINARY 1

typedef unsigned char PROCESS_FILETYPE;
struct process {
    uint16_t id;
    char filename[ORCAOS_MAX_PATH];
    struct task* task;
    void* allocations[ORCAOS_MAX_PROGRAM_ALLOCATIONS];
    PROCESS_FILETYPE filetype;
    union {
        void* ptr;
        struct elf_file* elf_file;
    };
    void* stack;
    uint32_t size;
    

    struct keyboard_buffer {
        char buffer[ORCAOS_KEYBOARD_BUFFER_SIZE];
        int tail;
        int head;
        
    } keyboard;
};

int process_switch(struct process* process);
int process_load_switch(const char* filename, struct process** process);
int process_load(const char* filename, struct process** process);
int process_load_for_slot(const char* filename, struct process** process, int process_slot);
struct process* process_current();
struct process* process_get(int process_id);
