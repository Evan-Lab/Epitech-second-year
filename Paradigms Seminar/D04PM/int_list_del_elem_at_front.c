/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** int_list_del_elem_at_front
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    if (int_list_get_size(*front_ptr) == 0)
        return false;
    *front_ptr = (*front_ptr)->next;
    return true;
}
