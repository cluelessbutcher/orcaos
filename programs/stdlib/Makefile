FILES=./build/start.asm.o ./build/orcaos.asm.o
INCLUDES=

all: $(FILES)
	ld -m elf_i386 -relocatable $(FILES) -o ./stdlib.elf

./build/start.asm.o: ./src/start.asm
	nasm -f elf ./src/start.asm -o ./build/start.asm.o

./build/orcaos.asm.o: ./src/orcaos.asm
	nasm -f elf ./src/orcaos.asm -o ./build/orcaos.asm.o

clean:
	rm -rf $(FILES)
	rm -rf ./stdlib.elf
