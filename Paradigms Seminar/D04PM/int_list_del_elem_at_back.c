/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** int_list_del_elem_at_back
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_node_t *tmp = *front_ptr;

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
