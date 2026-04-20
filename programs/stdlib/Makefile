FILES=./build/start.asm.o ./build/orcaos.asm.o ./build/stdlib.o ./build/stdio.o ./build/orcaos.o ./build/string.o ./build/memory.o ./build/start.o
INCLUDES=-I./src
FLAGS= -g -m32 -fno-pic -falign-jumps -falign-functions -falign-labels -falign-loops -fstrength-reduce -fomit-frame-pointer -finline-functions -Wno-unused-function -fno-builtin -Werror -Wno-unused-label -Wno-cpp -Wno-unused-parameter -nostdlib -nostartfiles -nodefaultlibs -Wall -O0 -Iinc

all: $(FILES)
	ld -m elf_i386 -relocatable $(FILES) -o ./stdlib.elf

./build/start.asm.o: ./src/start.asm
	nasm -f elf ./src/start.asm -o ./build/start.asm.o

./build/orcaos.asm.o: ./src/orcaos.asm
	nasm -f elf ./src/orcaos.asm -o ./build/orcaos.asm.o

./build/stdlib.o: ./src/stdlib.c
	gcc $(INCLUDES) $(FLAGS) -std=gnu99 -c ./src/stdlib.c -o ./build/stdlib.o

./build/stdio.o: ./src/stdio.c
	gcc $(INCLUDES) $(FLAGS) -std=gnu99 -c ./src/stdio.c -o ./build/stdio.o

./build/orcaos.o: ./src/orcaos.c
	gcc $(INCLUDES) $(FLAGS) -std=gnu99 -c ./src/orcaos.c -o ./build/orcaos.o

./build/string.o: ./src/string.c
	gcc $(INCLUDES) $(FLAGS) -std=gnu99 -c ./src/string.c -o ./build/string.o

./build/memory.o: ./src/memory.c
	gcc $(INCLUDES) $(FLAGS) -std=gnu99 -c ./src/memory.c -o ./build/memory.o

./build/start.o: ./src/start.c
	gcc $(INCLUDES) $(FLAGS) -std=gnu99 -c ./src/start.c -o ./build/start.o

clean:
	rm -rf $(FILES)
	rm -rf ./stdlib.elf
