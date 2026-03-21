FILES=./build/kernel.asm.o

all: ./bin/boot.bin ./bin/kernel.bin
	rm -rf ./bin/os.bin
	dd if=./bin/boot.bin >> ./bin/os.bin
	dd if=./bin/kernel.bin >> ./bin/os.bin
	dd if=/dev/zero bs=512 count=100 >> ./bin/os.bin

./bin/kernel.bin: $(FILES)
	ld -g -m elf_i386 -relocatable $(FILES) -o ./build/kernelfull.o
	gcc -m32 -T ./src/linker.ld -o ./bin/kernel.bin -ffreestanding -O0 -nostdlib ./build/kernelfull.o 

./bin/boot.bin: ./src/boot/boot.asm
	nasm -f bin ./src/boot/boot.asm -o ./bin/boot.bin	

./build/kernel.asm.o: ./src/kernel.asm
	nasm -f elf32 -g ./src/kernel.asm -o ./build/kernel.asm.o

clean:
	rm -rf ./bin/boot.bin
	rm -rf ./bin/os.bin
	rm -rf ./build/kernelfull.o
	rm -rf ${FILES}
