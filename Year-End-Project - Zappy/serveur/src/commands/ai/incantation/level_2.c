/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** level_2
*/

#include "incantation.h"

void do_incantation_level_2(client_t *client, info_game_t *info)
{
    remove_ressource(client, info->map, "linemate", 1);
    client->incantation_level++;
    send_end_incantation(info, client, "ok");
}

void incantation_level_2(client_t *client, info_game_t *info)
{
    int check = 0;

    check += check_ressource(client, info->map, "linemate", 1);
    if (check >= 1)
        do_incantation_level_2(client, info);
    else
        send_end_incantation(info, client, "ko");
}
