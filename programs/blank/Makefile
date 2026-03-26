all:
	nasm -f elf ./blank.asm -o ./build/blank.asm.o
	gcc -m32 -g -T ./linker.ld -o ./blank.bin -ffreestanding -O0 -nostdlib -fpic -g ./build/blank.asm.o

clean:
	rm -rf ./build/blank.asm.o
