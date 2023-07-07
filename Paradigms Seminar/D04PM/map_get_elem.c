/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** map_get_elem
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "map.h"
#include "list.h"

void *map_get_elem(map_t map, void *key, key_comparator_t key_cmp)
{
    node_t *node = map;
    while (node != NULL) {
        pair_t *pair = node->value;
        if (key_cmp(pair->key, key) == 0)
            return pair->value;
        node = node->next;
    }
    return NULL;
}
