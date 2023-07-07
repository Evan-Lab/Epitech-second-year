/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** level_4
*/

#include "incantation.h"

int check_inventory_level_4(client_t *client, info_game_t *info)
{
    int check = 0;

    check += check_ressource(client, info->map, "linemate", 2);
    check += check_ressource(client, info->map, "sibur", 1);
    check += check_ressource(client, info->map, "phiras", 2);
    return check;
}

void do_incantation_level_4(client_t *client, info_game_t *info)
{
    remove_ressource(client, info->map, "linemate", 2);
    remove_ressource(client, info->map, "sibur", 1);
    remove_ressource(client, info->map, "phiras", 2);
    client->incantation_level++;
    send_end_incantation(info, client, "ok");
}

void incantation_level_4(client_t *client, info_game_t *info)
{
    list_client_t *choosen = get_list_client_same_level(&info->list_client, 3,
    client->number_client);
    int check = 0;

    if (choose_client(&choosen, 1) == -1) {
        send_end_incantation(info, client, "ko");
        return;
    }
    check = check_inventory_level_4(client, info);
    if (check >= 3)
        do_incantation_level_4(client, info);
    else
        send_end_incantation(info, client, "ko");
}
