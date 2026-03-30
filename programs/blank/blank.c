#include "orcaos.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char** argv) {
    printf("My age is %i", 18);
    print("i fucking hate niggers they're black and they smell like shit");
        
    print(itoa(867));
    putchar('Z');

    void* ptr = malloc(512);
    free(ptr);
    while (1) {
        if (getkey() != 0) {
            print("Key was pressed");
        }
    }
    return 0;
}
