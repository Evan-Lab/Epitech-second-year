/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** sgt_command
*/

#include "server.h"

void sgt_command(client_t *client, info_serv_t *serv, char **arg)
{
    (void)arg;
    char *command = "sgt";
    char *time = my_itoa(serv->info_game.time_unit);
    int message_length = strlen(command) + strlen(time) + 2;
    char *message = malloc(sizeof(char) * (message_length + 1));

    sprintf(message, "%s %s\n", command, time);
    write(client->socket, message, message_length);
}
