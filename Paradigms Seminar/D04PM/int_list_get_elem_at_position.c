/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** int_list_get_elem_at_position
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    unsigned int len = int_list_get_size(list);
    if (position == 0)
        return int_list_get_elem_at_front(list);
    if (position > len)
        return false;
    for (unsigned int i = 0; list->next != NULL; list = list->next, i++)
        if (i == position)
            return list->value;
    return 0;
}
