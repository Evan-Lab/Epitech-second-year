/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** spawn_ressources
*/

#include "server.h"

void ressources_spawner(info_serv_t *serv, int max, int x, int y)
{
    int random = rand() % max;
    for (int count = 0; count < 7; count++) {
        serv->info_game.map[y][x].ressources[count].quantity += random;
    }
}

void take_all_map(info_serv_t *serv)
{
    int max = 3;

    for (int y = 0; y < serv->info_game.map_height; y++) {
        for (int x = 0; x < serv->info_game.map_width; x++) {
            x = rand() % serv->info_game.map_width;
            y = rand() % serv->info_game.map_height;
            ressources_spawner(serv, max, x, y);
        }
    }
}

void spawn_ressources_on_game(info_serv_t *serv)
{
    time_t current_time = time(NULL);

    serv->info_game.timer->seconds = difftime(current_time,
    serv->info_game.timer->startTime);
    if (serv->info_game.timer->seconds > 20) {
        take_all_map(serv);
        serv->info_game.timer->startTime = current_time;
        serv->info_game.timer->seconds = 0;
    }
}
