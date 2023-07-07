/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** int_list_is_empty
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool int_list_is_empty(int_list_t list)
{
    if (int_list_get_size(list) == 0)
        return true;
    return false;
}
