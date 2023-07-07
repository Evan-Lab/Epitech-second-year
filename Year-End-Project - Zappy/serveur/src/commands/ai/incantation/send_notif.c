/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** send_notif
*/

#include "incantation.h"

int define_nb_of_player(client_t *client)
{
    int level = client->incantation_level + 1;

    if (level == 2)
        return 0;
    if (level == 3 || level == 4)
        return 1;
    if (level == 5 || level == 6)
        return 3;
    if (level == 7 || level == 8)
        return 5;
    return 0;
}

void send_gui_info(int gui_socket, client_t *client, list_client_t *choose)
{
    list_client_t *head = choose;

    dprintf(gui_socket, "pic %d %d %d\n", client->x, client->y,
    client->incantation_level);
    while (head != NULL) {
        if (head->client->type == AI)
            dprintf(gui_socket, "%d", head->client->number_client);
        head = head->next;
        if (head != NULL)
            dprintf(gui_socket, " ");
        else
            dprintf(gui_socket, "\n");
    }
}

void start_incantation(info_game_t *info, client_t *client)
{
    list_client_t *choosen = get_list_client_same_level(&info->list_client,
    client->incantation_level + 1, client->number_client);
    int gui_socket = get_socket_gui(&info->list_client);

    if (choose_client(&choosen, define_nb_of_player(client)) == -1
    || gui_socket == -1)
        return;
    send_gui_info(gui_socket, client, choosen);
    dprintf(client->socket, "Elevation Underway\n");
}

void send_end_incantation(info_game_t *game, client_t *client, char *res)
{
    int gui_socket = get_socket_gui(&game->list_client);

    if (gui_socket == -1)
        return;
    dprintf(gui_socket, "pie %d %d %s\n", client->x, client->y,
    res);
    if (strcmp(res, "ko") == 0)
        dprintf(client->socket, "%s\n", res);
    else
        dprintf(client->socket, "Current level: %d\n",
        client->incantation_level);
}
