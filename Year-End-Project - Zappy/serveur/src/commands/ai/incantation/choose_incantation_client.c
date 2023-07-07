/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** choose_incantation_client
*/

#include "incantation.h"

list_client_t *get_list_client_same_level(list_client_t **list, int level,
int id)
{
    list_client_t *head = *list;
    list_client_t *new = NULL;

    while (head != NULL) {
        if (head->client->type == AI
        && head->client->incantaion_in_progress == 0
        && head->client->incantation_level == level
        && head->client->number_client != id)
            add_client(&new, head->client);
        head = head->next;
    }
    return new;
}

int get_len_list_client(list_client_t **list)
{
    list_client_t *head = *list;
    int count = 0;

    while (head != NULL) {
        ++count;
        head = head->next;
    }
    return count;
}

int choose_client(list_client_t **list, int min)
{
    list_client_t *head = *list;
    int choose = 0;
    int random_nbr = 0;

    if (get_len_list_client(list) < min)
        return -1;
    srand(time(0));
    while (choose < min) {
        random_nbr = 1 + rand() % 10;
        if (random_nbr > 5) {
            head->client->incantaion_in_progress = 1;
            ++choose;
        }
        head = head->next;
        if (head == NULL)
            head = *list;
    }
    return 0;
}
