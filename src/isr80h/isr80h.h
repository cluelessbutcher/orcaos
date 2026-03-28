#pragma once

enum SystemCommands {
    SYSTEM_COMMAND0_SUM,
    SYSTEM_COMMAND1_PRINT,
    SYSTEM_COMMAND2_GETKEY,
};

void isr80h_register_commands();
