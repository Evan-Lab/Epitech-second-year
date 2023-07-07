/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** left_command
*/

#include "server.h"

void left_command_second(client_t *client)
{
    if (strcmp(client->orientation_player, "2") == 0) {
        client->orientation_player = "1";
        dprintf(client->socket, "ok\n");
        return;
    }
    if (strcmp(client->orientation_player, "3") == 0) {
        client->orientation_player = "2";
        dprintf(client->socket, "ok\n");
        return;
    }
    if (strcmp(client->orientation_player, "4") == 0) {
        client->orientation_player = "3";
        dprintf(client->socket, "ok\n");
        return;
    }
}

void left_command(client_t *client, info_game_t *info, char *args)
{
    (void)args;
    (void)info;

    if (client->incantaion_in_progress == 1) {
        dprintf(client->socket, "ko\n");
        dprintf(client->socket, "ok\n");
        return;
    }
    if (strcmp(client->orientation_player, "1") == 0) {
        client->orientation_player = "4";
        dprintf(client->socket, "ok\n");
        return;
    }
    left_command_second(client);
}
