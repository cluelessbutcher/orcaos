[BITS 32]

section .text

global _start

_start:
    push message
    mov eax, 1
    int 0x80
    add esp, 4

    jmp $

section .data

message: db 'Im talking from the userland', 0
