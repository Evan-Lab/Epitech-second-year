/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** map_del_elem
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "map.h"
#include "list.h"

bool map_del_elem(map_t *map_ptr, void *key, key_comparator_t key_cmp)
{
    node_t *node = *map_ptr;
    while (node != NULL) {
        pair_t *pair = node->value;
        if (key_cmp(pair->key, key) == 0) {
            list_del_elem_at_front(map_ptr);
            return true;
        }
        node = node->next;
    }
    return false;
}
