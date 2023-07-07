/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** forward_command
*/

#include "server.h"

int forward_north(client_t *client, info_game_t *info)
{
    if (strcmp(client->orientation_player, "1") == 0 && client->y == 0) {
        client->y = info->map_height - 1;
        return 1;
    } else if (strcmp(client->orientation_player, "1") == 0) {
        client->y = client->y - 1;
        return 1;
    }
    return 0;
}

int forward_south(client_t *client, info_game_t *info)
{
    if (strcmp(client->orientation_player, "3") == 0
    && client->y == info->map_height - 1) {
        client->y = 0;
        return 1;
    } else if (strcmp(client->orientation_player, "3") == 0) {
        client->y = client->y + 1;
        return 1;
    }
    return 0;
}

int forward_east(client_t *client, info_game_t *info)
{
    if (strcmp(client->orientation_player, "2") == 0
    && client->x == info->map_width - 1) {
        client->x = 0;
        return 1;
    } else if (strcmp(client->orientation_player, "2") == 0) {
        client->x = client->x + 1;
        return 1;
    }
    return 0;
}

int forward_west(client_t *client, info_game_t *info)
{
    if (strcmp(client->orientation_player, "4") == 0 && client->x == 0) {
        client->x = info->map_width - 1;
        return 1;
    } else if (strcmp(client->orientation_player, "4") == 0) {
        client->x = client->x - 1;
        return 1;
    }
    return 0;
}

void forward_command(client_t *client, info_game_t *info, char *args)
{
    (void)args;
    int check = 0;

    if (client->incantaion_in_progress == 1) {
        dprintf(client->socket, "ko\n");
        return;
    }
    check += forward_north(client, info);
    check += forward_south(client, info);
    check += forward_east(client, info);
    check += forward_west(client, info);

    if (check == 1)
        dprintf(client->socket, "ok\n");
}
