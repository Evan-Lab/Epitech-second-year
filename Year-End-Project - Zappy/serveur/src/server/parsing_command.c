/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** parsing_command
*/

#include "server.h"
#include "command.h"

int len_array(char **array)
{
    int count = 0;

    while (array[count] != NULL)
        ++count;
    return (count - 1);
}

void send_error(client_t *data)
{
    if (data->type == GUI || data->type == None)
        dprintf(data->socket, "suc\n");
    if (data->type == AI)
        dprintf(data->socket, "ko\n");
}

ia_action_t *create_action(ia_command_t command, char **args)
{
    ia_action_t *action = malloc(sizeof(ia_action_t));

    if (action == NULL)
        return NULL;
    action->name = strdup(command.command);
    action->function = command.function;
    action->time = command.time;
    action->args = NULL;
    action->status = 0;
    if (len_array(args) > 1 && strncmp("Broadcast", command.command,
        strlen(command.command)) == 0)
        action->args = strdup(args[1]);
    if (len_array(args) > 0 && strncmp("Take", command.command,
        strlen(command.command)) == 0)
        action->args = strdup(args[1]);
    if (len_array(args) > 0 && strncmp("Set", command.command,
        strlen(command.command)) == 0)
        action->args = strdup(args[1]);
    return action;
}

void get_command_ai(char *command, client_t *data)
{
    char **args;
    int status_command = 0;
    ia_action_t *action;

    if (command == NULL || data->first_connection == 1 || data->type == GUI)
        return;
    for (int i = 0; ia_commands[i].command != NULL; i++) {
        if (strncmp(command, ia_commands[i].command,
        strlen(ia_commands[i].command)) == 0) {
            printf("COMMAND: %s\n", command);
            args = str_to_word_array(command, ' ');
            action = create_action(ia_commands[i], args);
            add_in_action_list(action, &data->action);
            free_array(args);
            status_command = 1;
            break;
        }
    }
    if (status_command == 0)
        send_error(data);
}
