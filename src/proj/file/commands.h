// This project is a part of CWorks (C language practice project).
//     Copyright (C) 2025. CarmJos
//
//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.


#ifndef COMMANDS_H
#define COMMANDS_H

#define MAX_COMMANDS 10
#define MAX_INPUT_LEN 256
#define MAX_ARGS 16

#include <stdbool.h>

typedef bool (*command_executor)(char **args, unsigned char length);

typedef struct {
    char *cmd;
    char *usage;
    char *description;
    command_executor execute;
} Command;

int register_command(command_executor func, const char *cmd,
                     const char *usage, const char *description);

void console_run(char *console_name, char *prefix);

#endif
