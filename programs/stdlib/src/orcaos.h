#pragma once

#include <stddef.h>
#include <stdbool.h>

struct command_argument {
    char argument[512];
    struct command_argument* next;
};

struct process_arguments {
    int argc;
    char** argv;
};

void* orcaos_malloc(size_t size);
void print(const char* message);
void orcaos_free(void* ptr);
void orcaos_putchar(char c);
void orcaos_terminal_readline(char* out, int max, bool output_while_typing);
void orcaos_process_load_start(const char* filename);
int orcaos_getkey();
int orcaos_getkeyblock();
struct command_argument* orcaos_parse_command(const char* command, int max);
void orcaos_process_get_arguments(struct process_arguments* arguments);
int orcaos_system(struct command_argument* arguments);
int orcaos_system_run(const char* command);
void orcaos_exit();
