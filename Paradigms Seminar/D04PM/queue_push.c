/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** queue_push
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"
#include "list.h"

bool queue_push(queue_t *queue_ptr, void *elem)
{
    return list_add_elem_at_back(queue_ptr, elem);
}
