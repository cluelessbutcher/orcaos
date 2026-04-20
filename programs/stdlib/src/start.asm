[BITS 32]

global _start

extern c_start
extern orcaos_exit

section .text

_start:
    	call c_start
	call orcaos_exit
    	ret
