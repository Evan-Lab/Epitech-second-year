/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** del_elem
*/

#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    node_t *tmp = *front_ptr;

    if (*front_ptr == NULL)
        return false;
    if (position == 0) {
        *front_ptr = tmp->next;
        free(tmp);
        return true;
    }
    for (unsigned int i = 0; i < position - 1; i++) {
        if (tmp->next == NULL)
            return false;
        tmp = tmp->next;
    }
    node_t *tmp2 = tmp->next;
    tmp->next = tmp2->next;
    free(tmp2);
    return true;
}

