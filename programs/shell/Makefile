FILES=./build/shell.o
INCLUDES=-I../stdlib/src
FLAGS= -g -m32 -fno-pic -falign-jumps -falign-functions -falign-labels -falign-loops -fstrength-reduce -fomit-frame-pointer -finline-functions -Wno-unused-function -fno-builtin -Werror -Wno-unused-label -Wno-cpp -Wno-unused-parameter -nostdlib -nostartfiles -nodefaultlibs -Wall -O0 -Iinc

all: $(FILES)
	gcc -g -m32 -T ./linker.ld -o ./shell.elf -ffreestanding -O0 -nostdlib -fpic -g $(FILES) ../stdlib/stdlib.elf

./build/shell.o: ./src/shell.c
	gcc $(INCLUDES) -I./ $(FLAGS) -std=gnu99 -c ./src/shell.c -o ./build/shell.o
