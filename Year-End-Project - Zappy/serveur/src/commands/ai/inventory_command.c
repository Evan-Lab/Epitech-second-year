/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** inventory_command
*/

#include "structure.h"
#include <stdio.h>

void inventory_command(client_t *client, info_game_t *info, char *args)
{
    (void)args;
    (void)info;

    dprintf(client->socket, "[");
    for (int count = 0; count < 7; ++count) {
        dprintf(client->socket, "%s %d", client->inventory[count].name,
        client->inventory[count].quantity);
        if (count + 1 < 7)
            dprintf(client->socket, ", ");
    }
    dprintf(client->socket, "]\n");
}
