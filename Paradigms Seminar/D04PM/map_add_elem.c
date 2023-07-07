/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** map_add_elem
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "map.h"
#include "list.h"

bool map_add_elem(map_t *map_ptr, void *key, void *value,
key_comparator_t key_cmp)
{
    pair_t *pair = malloc(sizeof(pair_t));
    pair->key = key;
    pair->value = value;
    return list_add_elem_at_front(map_ptr, pair);
    key_cmp = key_cmp;
}
