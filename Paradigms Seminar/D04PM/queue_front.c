/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** queue_front
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"
#include "list.h"

void *queue_front(queue_t queue)
{
    if (queue_is_empty(queue))
        return NULL;
    return queue->value;
}
