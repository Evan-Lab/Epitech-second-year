/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** fork_command
*/

#include "server.h"

void start_fork(client_t *client, info_game_t *info)
{
    int gui_socket = get_socket_gui(&info->list_client);

    if (gui_socket == -1)
        return;
    dprintf(gui_socket, "pfk %d\n", client->number_client);
}

void fork_command(client_t *client, info_game_t *info, char *args)
{
    (void) args;
    teams_t *teams = NULL;
    egg_t *eggs = NULL;
    int gui_socket = get_socket_gui(&info->list_client);
    if (info->map[client->y][client->x].egg == 1) {
        dprintf(client->socket, "ko\n");
        return;
    }
    teams = get_teams_by_name(&info->teams_name, client->team_name);
    teams->nb_connection++;
    eggs = malloc(sizeof(egg_t));
    init_eggs(eggs, client->x, client->y, 1);
    set_id_eggs(eggs, info);
    add_eggs(&teams->list_egg, eggs);
    dprintf(client->socket, "ok\n");
    if (gui_socket != -1)
        dprintf(gui_socket, "enw %d %d %d %d\n", eggs->id,
        client->number_client,
        eggs->x, eggs->y);
}
