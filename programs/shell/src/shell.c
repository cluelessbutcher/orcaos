#include "shell.h"
#include "stdio.h"
#include "stdlib.h"
#include "orcaos.h"

int main(int argc, char** argv) {
    print("OrcaOS v1.0.0");
    while (1) {
        print("> ");
        char buf[1024];
        orcaos_terminal_readline(buf, sizeof(buf), true);
        print("\n");
        orcaos_system_run(buf);
        print("\n");
    }
    return 0;
}   
