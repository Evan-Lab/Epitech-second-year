/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** queue_is_empty
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"
#include "list.h"

bool queue_is_empty(queue_t queue)
{
    return list_is_empty(queue);
}
