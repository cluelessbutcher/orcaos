FILES=./build/start.asm.o ./build/orcaos.asm.o ./build/stdlib.o
INCLUDES=-I./src
FLAGS= -g -m32

all: $(FILES)
	ld -m elf_i386 -relocatable $(FILES) -o ./stdlib.elf

./build/start.asm.o: ./src/start.asm
	nasm -f elf ./src/start.asm -o ./build/start.asm.o

./build/orcaos.asm.o: ./src/orcaos.asm
	nasm -f elf ./src/orcaos.asm -o ./build/orcaos.asm.o

./build/stdlib.o: ./src/stdlib.c
	gcc $(INCLUDES) $(FLAGS) -std=gnu99 -c ./src/stdlib.c -o ./build/stdlib.o

clean:
	rm -rf $(FILES)
	rm -rf ./stdlib.elf
