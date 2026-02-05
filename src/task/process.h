#ifndef PROCESS_H
#define PROCESS_H

#include <stdint.h>
#include "task.h"
#include "config.h"

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
int process_load(const char* filename, struct process** process);
struct process* process_current();
struct process* process_get(int process_id);

#endif