/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** int_list_get_elem_at_front
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int int_list_get_elem_at_front(int_list_t list)
{
    if (int_list_get_size(list) == 0)
        return 0;
    return list->value;
}
