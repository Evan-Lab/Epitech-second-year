/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** queue_pop
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"
#include "list.h"

bool queue_pop(queue_t *queue_ptr)
{
    return list_del_elem_at_front(queue_ptr);
}
