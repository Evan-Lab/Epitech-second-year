/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** get_elem
*/

#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void *list_get_elem_at_front(list_t list)
{
    return list->value;
}

void *list_get_elem_at_back(list_t list)
{
    node_t *tmp = list;

    for (; tmp->next != NULL; tmp = tmp->next);
    return tmp->value;
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    node_t *tmp = list;

    for (unsigned int i = 0; i < position; i++) {
        if (tmp->next == NULL)
            return NULL;
        tmp = tmp->next;
    }
    return tmp->value;
}

