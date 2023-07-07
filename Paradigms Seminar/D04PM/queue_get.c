/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** queue_get
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"
#include "list.h"

unsigned int queue_get_size(queue_t queue)
{
    return list_get_size(queue);
}
