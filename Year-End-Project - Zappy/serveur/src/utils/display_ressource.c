/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** display_ressources
*/

#include "server.h"

void print_all_quantity(char *name, int quantity, client_t *client)
{
    for (int count = 0; count < quantity; ++count) {
        dprintf(client->socket, "%s", name);
        if (count + 1 < quantity)
            dprintf(client->socket, " ");
    }
}

void print_ressource(int x, int y, map_t **map, client_t *client)
{
    for (int count = 0; count < 7; ++count) {
        if (map[y][x].ressources[count].quantity > 0)
            print_all_quantity(map[y][x].ressources[count].name,
            map[y][x].ressources[count].quantity, client);
        if (count + 1 < 7 && map[y][x].ressources[count + 1].quantity > 0)
            dprintf(client->socket, " ");
    }
}

void display_column_ressource(int x, int *tab, client_t *client,
info_game_t *info)
{
    int count = 0;
    int y_min = tab[0];
    int y_max = tab[1];

    for (; y_min <= y_max; ++y_min) {
        count = y_min;
        if (y_min >= info->map_height)
            count = y_min - info->map_height;
        if (y_min < 0)
            count = info->map_height - abs(y_min);
        if (info->map[count][x].client != NULL)
            dprintf(client->socket, "player ");
        print_ressource(x, count, info->map, client);
        if (y_min + 1 <= y_max)
            dprintf(client->socket, ",");
    }
}

void display_line_ressource(int y, int *tab, client_t *client,
info_game_t *info)
{
    int count = 0;
    int x_min = tab[0];
    int x_max = tab[1];

    for (; x_min <= x_max; ++x_min) {
        count = x_min;
        if (x_min >= info->map_width)
            count = x_min - info->map_width;
        if (x_min < 0)
            count = info->map_width - abs(x_min);
        if (info->map[y][count].client != NULL)
            dprintf(client->socket, "player");
        print_ressource(count, y, info->map, client);
        if (x_min + 1 <= x_max)
            dprintf(client->socket, ",");
    }
}
