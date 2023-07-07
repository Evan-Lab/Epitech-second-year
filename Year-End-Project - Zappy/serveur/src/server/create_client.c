/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** create_client
*/

#include "zappy_server.h"
#include "server.h"

void add_client(list_client_t **list, client_t *client)
{
    list_client_t *node = malloc(sizeof(list_client_t));
    list_client_t *head = *list;

    client->action = NULL;
    client->type = None;
    node->client = client;
    node->next = NULL;
    if (*list == NULL) {
        *list = node;
        return;
    }
    while (head->next != NULL)
        head = head->next;
    head->next = node;
}

client_t *get_client_by_id(int id, list_client_t **list)
{
    list_client_t *head = *list;

    while (head != NULL) {
        if (head->client->socket == id)
            return head->client;
        head = head->next;
    }
    return NULL;
}
