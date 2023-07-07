/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** gui_command
*/

#include "server.h"

void exec_gui(char *command, client_t *data, info_serv_t *serv, int count)
{
    char **args = NULL;

    if (strncmp(command, commands[count].command,
        strlen(commands[count].command)) == 0) {
        args = str_to_word_array(command, ' ');
        commands[count].function(data, serv, args);
        free_array(args);
    }
}

void get_command(char *command, client_t *data, info_serv_t *serv)
{
    char **command_list;
    char **args;
    (void) args;

    if (command == NULL || data->first_connection == 1 || data->type == AI)
        return;
    command_list = str_to_word_array(command, '\n');
    for (int index_args = 0; command_list[index_args] != NULL; ++index_args) {
        for (int i = 0; commands[i].command != NULL; i++) {
            exec_gui(command_list[index_args], data, serv, i);
        }
    }
}
