[BITS 32]

section .asm

global restore_general_purpose_registers
global task_return
global user_registers


task_return:
	mov ebp, esp

	; let's access the structure passed to us
	mov ebx, [ebp+4]
	; push the data/stack selector
	push dword [ebx+44]
	; push the stack pointer
	push dword [ebx+40]
	; push the flags
	mov eax, [ebx+36]
	or eax, 0x200					; interrupt enable flag set
	push eax

	; push the code segment
	push dword [ebx+32]
	; push the ip to execute
	push dword [ebx+28]

	; setup some segment registers
	mov ax, [ebx+44]
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	push dword [ebp+4]
	call restore_general_purpose_registers
	add esp, 4

	iretd

restore_general_purpose_registers:
	push ebp
	mov ebp, esp
	mov ebx, [ebp+8]
	mov edi, [ebx]
	mov esi, [ebx+4]
	mov ebp, [ebx+8]
	mov edx, [ebx+16]
	mov ecx, [ebx+20]
	mov eax, [ebx+24]
	mov ebx, [ebx+12]
	add esp, 4
	ret

user_registers:
	mov ax, 0x23
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	ret
