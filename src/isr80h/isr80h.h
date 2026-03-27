#pragma once

enum SystemCommands {
    SYSTEM_COMMAND0_SUM,
    SYSTEM_COMMAND1_PRINT,
};

void isr80h_register_commands();
