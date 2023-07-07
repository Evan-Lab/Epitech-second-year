/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** get_size
*/

#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

unsigned int list_get_size(list_t list)
{
    unsigned int len = 0;
    node_t *tmp = list;

    for (; tmp != NULL; tmp = tmp->next)
        len += 1;
    return len;
}
