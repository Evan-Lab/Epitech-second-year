/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** set_object_down_command
*/

#include "server.h"

void set_object_command(client_t *client, info_game_t *info, char *args)
{
    int gui_socket = get_socket_gui(&info->list_client);
    int i = -1;

    if (args == NULL) {
        dprintf(client->socket, "ko\n");
        return;
    }
    args = strdup(clean_str(args, '\n'));
    i = take_arg(args);
    if (i > -1 && client->inventory[i].quantity > 0) {
        client->inventory[i].quantity--;
        info->map[client->y][client->x].ressources[i].quantity++;
        dprintf(client->socket, "ok\n");
        dprintf(gui_socket, "pdr %d %d\n", client->number_client, i);
    } else
        dprintf(client->socket, "ko\n");
}
