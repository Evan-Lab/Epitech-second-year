/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** int_list_get_size
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

unsigned int int_list_get_size(int_list_t list)
{
    unsigned int len = 0;
    for (; list != NULL; list = list->next)
        len += 1;
    return len;
}
