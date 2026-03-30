#include "stdlib.h"
#include "orcaos.h"

void* malloc(size_t size) {
    return orcaos_malloc(size);
}

void free(void* ptr) {
    orcaos_free(ptr);        
}
