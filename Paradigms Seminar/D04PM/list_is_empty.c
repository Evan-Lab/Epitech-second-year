/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** list_is_empty
*/

#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool list_is_empty(list_t list)
{
    if (list_get_size(list) == 0)
        return true;
    return false;
}
