/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** get_socket_gui
*/

#include "server.h"

int get_socket_gui(list_client_t **list)
{
    list_client_t *head = *list;

    while (head != NULL) {
        if (head->client->first_connection == 0 &&
        head->client->type == GUI) {
            return head->client->socket;
        }
        head = head->next;
    }
    return -1;
}
