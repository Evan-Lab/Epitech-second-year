/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** init_server
*/

#include "zappy_server.h"
#include "server.h"

void init_things(info_serv_t *serv)
{
    init_ressources(&serv->info_game);
    create_map(&serv->info_game);
    ressources_distribution(&serv->info_game);
}
