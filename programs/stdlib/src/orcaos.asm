[BITS 32]

global print:function
global getkey:function
global orcaos_malloc:function

print:
    push ebp
    mov ebp, esp
    push dword[ebp+8]
    mov eax, 1
    int 0x80
    add esp, 4
    pop ebp
    ret

getkey:
    push ebp
    mov ebp, esp
    mov eax, 2
    int 0x80
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
