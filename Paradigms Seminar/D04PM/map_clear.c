/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** map_clear
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "map.h"
#include "list.h"

void map_clear(map_t *map_ptr)
{
    node_t *node = *map_ptr;
    while (node != NULL) {
        pair_t *pair = node->value;
        free(pair);
        node = node->next;
    }
    list_clear(map_ptr);
}
