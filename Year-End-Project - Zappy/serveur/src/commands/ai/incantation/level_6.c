/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** level_6
*/

#include "incantation.h"

int check_inventory_level_6(client_t *client, info_game_t *info)
{
    int check = 0;

    check += check_ressource(client, info->map, "linemate", 1);
    check += check_ressource(client, info->map, "deraumere", 2);
    check += check_ressource(client, info->map, "sibur", 1);
    check += check_ressource(client, info->map, "mendiane", 3);
    return check;
}

void do_incantation_level_6(client_t *client, info_game_t *info)
{
    remove_ressource(client, info->map, "linemare", 1);
    remove_ressource(client, info->map, "deraumere", 2);
    remove_ressource(client, info->map, "sibur", 1);
    remove_ressource(client, info->map, "mendiane", 3);
    client->incantation_level++;
    send_end_incantation(info, client, "ok");
}

void incantation_level_6(client_t *client, info_game_t *info)
{
    list_client_t *choosen = get_list_client_same_level(&info->list_client, 5,
    client->number_client);
    int check = 0;

    if (choose_client(&choosen, 3) == -1) {
        send_end_incantation(info, client, "ko");
        return;
    }
    check = check_inventory_level_6(client, info);
    if (check >= 4)
        do_incantation_level_6(client, info);
    else
        send_end_incantation(info, client, "ko");
}
