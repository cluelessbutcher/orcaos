section .asm

extern int21h_handler
extern no_interrupt_handler
extern isr80h_handler

global idt_load
global int21h
global no_interrupt
global enable_interrupts
global disable_interrupts
global isr80h_wrapper

idt_load:
    	push ebp
    	mov ebp, esp
    	mov ebx, [ebp+8]
    	lidt[ebx]
    	pop ebp
    	ret

enable_interrupts:
    	sti
    	ret

disable_interrupts:
	cli
	ret

int21h:
	cli
	pushad
	call int21h_handler
	popad
	sti
	iret

no_interrupt:
	cli
	pushad
	call no_interrupt_handler
	popad
	sti
	iret

isr80h_wrapper:
	pushad				; interrupts frame end
	push esp
	push eax
	call isr80h_handler
	mov dword[tmp_res], eax
	add esp, 8
	popad
	mov eax, [tmp_res]
	iretd

section .data

tmp_res: dd 0
