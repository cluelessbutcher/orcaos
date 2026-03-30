#pragma once

#include <stddef.h>
#include <stdbool.h>

void* orcaos_malloc(size_t size);
void print(const char* message);
void orcaos_free(void* ptr);
void orcaos_putchar(char c);
void orcaos_terminal_readline(char* out, int max, bool output_while_typing);
int orcaos_getkey();
int orcaos_getkeyblock();
