/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** list_del_elem
*/

#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool list_del_elem_at_back(list_t *front_ptr)
{
    node_t *tmp = *front_ptr;

    if (*front_ptr == NULL)
        return false;
    if (tmp->next == NULL) {
        *front_ptr = NULL;
        free(tmp);
        return true;
    }
    for (; tmp->next->next != NULL; tmp = tmp->next);
    free(tmp->next);
    tmp->next = NULL;
    return true;
}

bool list_del_elem_at_front(list_t *front_ptr)
{
    node_t *tmp = *front_ptr;

    if (*front_ptr == NULL)
        return false;
    *front_ptr = tmp->next;
    free(tmp);
    return true;
}
