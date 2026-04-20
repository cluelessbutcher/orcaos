[BITS 32]

section .text

global print:function
global orcaos_getkey:function
global orcaos_malloc:function
global orcaos_free:function
global orcaos_putchar:function
global orcaos_process_load_start:function
global orcaos_process_get_arguments:function
global orcaos_system:function
global orcaos_exit:function

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

orcaos_process_load_start:
    push ebp
    mov ebp, esp
    mov eax, 6
    push dword[ebp+8]
    int 0x80
    add esp, 4
    pop ebp
    ret

orcaos_system:
	push ebp
	mov ebp, esp
	mov eax, 7
	push dword[ebp+8]
	int 0x80
	add esp, 4
	pop ebp
	ret

orcaos_process_get_arguments:
    push ebp
    mov ebp, esp
    mov eax, 8
    push dword[ebp+8]
    int 0x80
    add esp, 4
    pop ebp
    ret

orcaos_exit:
	push ebp
	mov ebp, esp
	mov eax, 9
	int 0x80
	pop ebp
	ret 
