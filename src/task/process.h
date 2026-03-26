#pragma once

#include "config.h"
#include "task.h"
#include <stdint.h>

struct process {
    uint16_t id;
    char filename[ORCAOS_MAX_PATH];
    struct task* task;
    void* allocations[ORCAOS_MAX_PROGRAM_ALLOCATIONS];
    void* ptr;
    void* stack;
    uint32_t size;
};

int process_load_for_slot(const char* filename, struct process** process, int process_slot);
