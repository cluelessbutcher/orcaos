FILES=./build/blank.o
INCLUDES=-I../stdlib/src
FLAGS= -g -m32
all: $(FILES)
	gcc -m32 -g -T ./linker.ld -o ./blank.elf -ffreestanding -O0 -nostdlib -fpic -g $(FILES) ../stdlib/stdlib.elf

./build/blank.o: ./blank.c
	gcc $(INCLUDES) -I./ $(FLAGS) -std=gnu99 -c ./blank.c -o ./build/blank.o

clean:
	rm -rf $(FILES)
	rm -rf ./blank.elf
