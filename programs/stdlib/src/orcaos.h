#pragma once

#include <stddef.h>

void print(const char* message);
void* orcaos_malloc(size_t size);
void orcaos_free(void* ptr);
int getkey();
void orcaos_putchar(char c);
