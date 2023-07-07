/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** list_dump
*/

#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void list_dump(list_t list, value_displayer_t val_disp)
{
    node_t *current = list;
    while (current != NULL) {
        val_disp(current->value);
        current = current->next;
    }
}
