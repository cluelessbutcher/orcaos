[BITS 32]

section .text

global _start

_start:
    call getkey
    push message
    mov eax, 1
    int 0x80
    add esp, 4


    jmp $

getkey:
    mov eax, 2
    int 0x80
    cmp eax, 0x00
    je getkey
    ret

section .data

message: db 'Im talking from the userland', 0
