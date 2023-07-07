/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** remove_ressource
*/

#include "incantation.h"

int check_ressource(client_t *client, map_t **map, char *name, int nb)
{
    for (int count = 0; count < 7; ++count) {
        if (strcmp(map[client->y][client->x].ressources[count].name, name) == 0
        && map[client->y][client->x].ressources[count].quantity >= nb) {
            return 1;
        }
    }
    return -1;
}

int remove_ressource(client_t *client, map_t **map, char *name, int nb)
{
    for (int count = 0; count < 7; ++count) {
        if (strcmp(map[client->y][client->x].ressources[count].name, name) == 0
        && map[client->y][client->x].ressources[count].quantity >= nb) {
            map[client->y][client->x].ressources[count].quantity -= nb;
            return 0;
        }
    }
    return -1;
}
