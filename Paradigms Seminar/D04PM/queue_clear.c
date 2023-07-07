/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** queue_clear
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"
#include "list.h"

void queue_clear(queue_t *queue_ptr)
{
    list_clear(queue_ptr);
}
