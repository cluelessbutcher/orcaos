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

    orcaos_getkeyblock();
    print("This is my second bullshit message");

    char buf[1024];
    orcaos_terminal_readline(buf, sizeof(buf), true);
    print(buf);

    while (1) {}
    return 0;
}
