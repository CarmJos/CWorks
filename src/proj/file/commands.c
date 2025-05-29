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


#include "commands.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static Command commands[MAX_COMMANDS];
static int command_count = 0;

int register_command(const command_executor func, const char *cmd,
                     const char *usage, const char *description) {
    if (command_count >= MAX_COMMANDS) {
        fprintf(stderr, "Command registry full.\n");
        return -1;
    }
    commands[command_count].cmd = strdup(cmd);
    commands[command_count].usage = strdup(usage);
    commands[command_count].description = strdup(description);
    commands[command_count].execute = func;
    command_count++;
    return 0;
}

int parse_args(char *input, char *args[]) {
    int argc = 0;
    char *token = strtok(input, " \t\n");

    while (token && argc < MAX_ARGS) {
        args[argc++] = token;
        token = strtok(NULL, " \t\n");
    }
    return argc;
}

void show_usages(const Command *cmd) {
    printf("# %s %s\n - %s\n", cmd->cmd, cmd->usage, cmd->description);
}

bool help_command(char **args, const unsigned char length) {
    printf("Available commands: \n");
    for (int i = 0; i < command_count; i++) {
        show_usages(&commands[i]);
    }
    return true;
}

void console_run(char *console_name, char *prefix) {
    char input[MAX_INPUT_LEN];
    char *args[MAX_ARGS];

    register_command(help_command, "help", "", "Show commands and usages.");

    printf("%s console (types 'exit' to quit)\n", console_name);
    while (1) {
        printf("\n%s ", prefix);
        if (!fgets(input, MAX_INPUT_LEN, stdin)) break;
        if (strncmp(input, "exit", 4) == 0) break;
        const int argc = parse_args(input, args);
        if (argc == 0) continue;

        bool found = false;
        for (int i = 0; i < command_count; i++) {
            if (strcmp(args[0], commands[i].cmd) == 0) {
                if (!commands[i].execute(&args[1], argc - 1)) {
                    printf("Usages: \n");
                    show_usages(&commands[i]);
                }
                found = true;
                break;
            }
        }

        if (!found) printf("Unknown command: '%s', use 'help' for instructions.\n", args[0]);
    }
}
