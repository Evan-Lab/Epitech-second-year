/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** look_command
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"

void look_north(client_t *client, info_game_t *info)
{
    int count_y = client->y;
    int tab[2] = {0, 0};

    dprintf(client->socket, "[");
    dprintf(client->socket, "player ");
    print_ressource(client->x, client->y, info->map, client);
    dprintf(client->socket, ",");
    for (int count = 1; count <= client->incantation_level;
    ++count, --count_y) {
        tab[0] = client->x - count;
        tab[1] = client->x + count;
        if (count_y < 0)
            count_y = info->map_height - 1;
        display_line_ressource(count_y, tab, client, info);
        if (count + 1 <= client->incantation_level)
            dprintf(client->socket, ",");
    }
    dprintf(client->socket, "]\n");
}

void look_south(client_t *client, info_game_t *info)
{
    int count_y = client->y;
    int tab[2] = {0, 0};

    dprintf(client->socket, "[");
    dprintf(client->socket, "player ");
    print_ressource(client->x, client->y, info->map, client);
    dprintf(client->socket, ",");
    for (int count = 1; count <= client->incantation_level;
    ++count, ++count_y) {
        tab[0] = client->x - count;
        tab[1] = client->x + count;
        if (count_y >= info->map_height)
            count_y = 0;
        display_line_ressource(count_y, tab, client, info);
        if (count + 1 <= client->incantation_level)
            dprintf(client->socket, ",");
    }
    dprintf(client->socket, "]\n");
}

void look_west(client_t *client, info_game_t *info)
{
    int count_x = client->x - 1;
    int tab[2] = {0, 0};

    dprintf(client->socket, "[");
    dprintf(client->socket, "player ");
    print_ressource(client->x, client->y, info->map, client);
    dprintf(client->socket, ",");
    for (int count = 1; count <= client->incantation_level;
    ++count, ++count_x) {
        tab[0] = client->y - count;
        tab[1] = client->y + count;
        if (count_x < 0)
            count_x = info->map_width - 1;
        display_column_ressource(count_x, tab, client, info);
        if (count + 1 <= client->incantation_level)
            dprintf(client->socket, ",");
    }
    dprintf(client->socket, "]\n");
}

void look_east(client_t *client, info_game_t *info)
{
    int count_x = (client->x + 1 >= info->map_width) ? 0 : client->x + 1;
    int tab[2] = {0, 0};

    dprintf(client->socket, "[");
    dprintf(client->socket, "player ");
    print_ressource(client->x, client->y, info->map, client);
    dprintf(client->socket, ",");
    for (int count = 1; count <= client->incantation_level;
    ++count, ++count_x) {
        tab[0] = client->y - count;
        tab[1] = client->y + count;
        if (count_x < 0)
            count_x = info->map_width - 1;
        display_column_ressource(count_x, tab, client, info);
        if (count + 1 <= client->incantation_level)
            dprintf(client->socket, ",");
    }
    dprintf(client->socket, "]\n");
}

void look_command(client_t *client, info_game_t *info, char *args)
{
    (void)args;

    if (strcmp(client->orientation_player, "1") == 0)
        look_north(client, info);
    if (strcmp(client->orientation_player, "3") == 0)
        look_south(client, info);
    if (strcmp(client->orientation_player, "2") == 0)
        look_east(client, info);
    if (strcmp(client->orientation_player, "4") == 0)
        look_west(client, info);
}
