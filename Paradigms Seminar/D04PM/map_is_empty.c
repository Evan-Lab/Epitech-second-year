/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** map_is_empty
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "map.h"
#include "list.h"


bool map_is_empty(map_t map)
{
    return list_is_empty(map);
}
