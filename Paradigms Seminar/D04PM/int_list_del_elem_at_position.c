/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** int_list_del_elem_at_position
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool int_list_del_elem_at_position(int_list_t *front_ptr,
unsigned int position)
{
    if (int_list_get_size(*front_ptr) == 0)
        return false;
    if (position == 0)
        return int_list_del_elem_at_front(front_ptr);
    if (position > int_list_get_size(*front_ptr))
        return false;

    int_list_t tmp = *front_ptr;
    int_list_t to_delete = NULL;

    for (unsigned int i = 1; i != position; i++) {
        tmp = tmp->next;
    }
    to_delete = tmp->next->next;
    free(tmp->next);
    tmp->next = to_delete;
    return true;
}
