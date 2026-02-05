#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 20

#define ERROR(value) (void*)(value)
#define ISERR(ptr)   ((intptr_t)(ptr) < 0)
#define ERROR_I(ptr) ((intptr_t)(ptr))

void kernel_main();
void print(const char* str);
void panic(const char* msg);
void kernel_page();
void kernel_registers();

#endif
