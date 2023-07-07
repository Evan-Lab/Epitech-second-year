/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** list_clear
*/

#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void list_clear(list_t *front)
{
    node_t *tmp = *front;
    node_t *tmp2 = NULL;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2;
    }
    *front = NULL;
}
