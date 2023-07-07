/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** map_get
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "map.h"
#include "list.h"

unsigned int map_get_size(map_t map)
{
    return list_get_size(map);
}
