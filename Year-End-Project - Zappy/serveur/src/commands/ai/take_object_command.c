/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** take_object_function
*/

#include "server.h"

int take_arg(char *args)
{
    int i = -1;

    if (strcmp(args, "food") == 0)
        i = 0;
    if (strcmp(args, "linemate") == 0)
        i = 1;
    if (strcmp(args, "deraumere") == 0)
        i = 2;
    if (strcmp(args, "sibur") == 0)
        i = 3;
    if (strcmp(args, "mendiane") == 0)
        i = 4;
    if (strcmp(args, "phiras") == 0)
        i = 5;
    if (strcmp(args, "thystame") == 0)
        i = 6;
    return i;
}

void take_object_command(client_t *client, info_game_t *info, char *args)
{
    int gui_socket = get_socket_gui(&info->list_client);
    int i = -1;

    if (args == NULL) {
        dprintf(client->socket, "ko\n");
        return;
    }
    args = strdup(clean_str(args, '\n'));
    i = take_arg(args);
    if (i > -1 && info->map[client->y][client->x].ressources[i].quantity > 0) {
        client->inventory[i].quantity = client->inventory[i].quantity + 1;
        info->map[client->y][client->x].ressources[i].quantity--;
        dprintf(client->socket, "ok\n");
        dprintf(gui_socket, "pgt %d %d\n", client->number_client, i);
    } else {
        dprintf(client->socket, "ko\n");
    }
}
