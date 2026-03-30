#pragma once

#include "elf.h"
#include "config.h"
#include <stdint.h>
#include <stddef.h>

struct elf_file {
    char filename[ORCAOS_MAX_PATH];
    int in_memory_size;
    void* elf_memory;
    void* virtual_base_address;
    void* virtual_end_address;
    void* physical_base_address;
    void* physical_end_address;
};

int elf_load(const char* filename, struct elf_file** file_out);
void* elf_memory(struct elf_file* file);
struct elf_header* elf_header(struct elf_file* file);
struct elf32_shdr* elf_sheader(struct elf_header* header);
struct elf32_phdr* elf_pheader(struct elf_header* header);
struct elf32_phdr* elf_program_header(struct elf_header* header, int index);
struct elf32_shdr* elf_section(struct elf_header* header, int index);
char* elf_str_table(struct elf_header* header);
void* elf_virtual_base(struct elf_file* file);
void* elf_virtual_end(struct elf_file* file);
void* elf_phys_base(struct elf_file* file);
void* elf_phys_end(struct elf_file* file);
int elf_validate_loaded(struct elf_header* header);
int elf_process_phdr_pt_load(struct elf_file* elf_file, struct elf32_phdr* phdr);
int elf_process_pheader(struct elf_file* elf_file, struct elf32_phdr* phdr);
int elf_process_pheaders(struct elf_file* elf_file);
int elf_process_loaded(struct elf_file* elf_file);
int elf_load(const char* filename, struct elf_file** file_out);
void elf_close(struct elf_file* file);
void* elf_phdr_phys_address(struct elf_file* file, struct elf32_phdr* phdr);
