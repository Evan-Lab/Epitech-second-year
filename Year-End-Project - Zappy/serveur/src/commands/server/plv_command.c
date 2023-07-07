/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** plv_command
*/

#include "server.h"

void print_plv(client_t *client, client_t *gui)
{
    if (client == NULL)
        return;
    dprintf(gui->socket, "plv %d %d\n", client->socket,
    client->incantation_level);
}

void plv_command(client_t *client, info_serv_t *serv, char **args)
{
    int size_args = get_len_double_char(args);
    char *id;
    client_t *get_cli;

    if (size_args != 2) {
        dprintf(client->socket, "sbp\n");
        return;
    }
    id = strdup(args[1]);
    id = strdup(clean_str(id, '#'));
    id = strdup(clean_str(id, '\n'));
    id = strdup(clean_str(id, '\r'));
    if (check_int(id) == -1) {
        dprintf(client->socket, "sbp\n");
        return;
    }
    get_cli = get_client_by_id(atoi(id), &serv->info_game.list_client);
    free(id);
    print_plv(get_cli, client);
}
