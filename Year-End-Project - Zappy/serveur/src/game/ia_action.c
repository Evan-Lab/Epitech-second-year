/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** ia_action
*/

#include <stdlib.h>
#include "structure.h"

void add_in_action_list(ia_action_t *action, list_action_t **list)
{
    list_action_t *node = malloc(sizeof(list_action_t));
    list_action_t *head = *list;

    if (node == NULL)
        return;
    node->action = action;
    node->next = NULL;
    if (*list == NULL) {
        *list = node;
        return;
    }
    while (head->next != NULL)
        head = head->next;
    head->next = node;
}

void remove_element_at(int index, list_action_t **list)
{
    list_action_t *head = *list;
    list_action_t *previous;
    int count = 0;

    if (head == NULL)
        return;
    while (count < index && head != NULL) {
        previous = head;
        head = head->next;
    }
    if (head == NULL || count < index)
        return;
    if (head != NULL) {
        free(head);
        head = previous;
    }
}

int get_len_list_action(list_action_t *list)
{
    list_action_t *head = list;
    int count = 0;

    while (head != NULL) {
        ++count;
        head = head->next;
    }
    return count;
}
