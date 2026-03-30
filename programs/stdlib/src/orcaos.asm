[BITS 32]

section .text

global print:function
global orcaos_getkey:function
global orcaos_malloc:function
global orcaos_free:function
global orcaos_putchar:function

print:
    push ebp
    mov ebp, esp
    push dword[ebp+8]
    mov eax, 1
    int 0x80
    add esp, 4
    pop ebp
    ret

orcaos_getkey:
    push ebp
    mov ebp, esp
    mov eax, 2
    int 0x80
    pop ebp
    ret

orcaos_putchar:
    push ebp
    mov ebp, esp
    mov eax, 3
    push dword[ebp+8]
    int 0x80
    add esp, 4
    pop ebp
    ret

orcaos_malloc:
    push ebp
    mov ebp, esp
    mov eax, 4
    push dword[ebp+8]
    int 0x80
    add esp, 4
    pop ebp
    ret

orcaos_free:
    push ebp
    mov ebp, esp
    mov eax, 5
    push dword[ebp+8]
    int 0x80
    add esp, 4
    pop ebp
    ret
