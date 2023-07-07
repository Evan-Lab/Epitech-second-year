/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** death_of_an_ia
*/

#include "server.h"

int remove_client(client_t *client, info_game_t *game)
{
    list_client_t *head = game->list_client;

    if (head == NULL)
        return -1;
    while (head->next != NULL) {
        if (head->client->socket == client->socket) {
            head->next = head->next->next;
            return 0;
        }
        head = head->next;
    }
    if (head->next == NULL) {
        game->list_client = NULL;
        return 0;
    }
    return -1;
}

void create_clock_for_player(client_t *client)
{
    client->client_clock = malloc(sizeof(clock_struct_t));
    client->client_clock->startTime = time(NULL);
    client->client_clock->seconds = 0;
}

void player_death(client_t *client, info_serv_t *serv)
{
    int socket_gui = get_socket_gui(&serv->info_game.list_client);
    int frenquency = 1260 / serv->info_game.time_unit;

    if (client->type == AI && difftime(time(NULL),
    client->client_clock->startTime) >= frenquency) {
        client->inventory[0].quantity--;
        client->client_clock->startTime = time(NULL);
    }
    if (client->type == AI && client->inventory[0].quantity <= 0) {
        dprintf(socket_gui, "pdi %d\n", client->number_client);
        dprintf(client->socket, "dead\n");
        if (close(client->socket) == -1)
            return;
        FD_CLR(client->socket, &serv->socket_list);
        remove_client(client, &serv->info_game);
    }
}
