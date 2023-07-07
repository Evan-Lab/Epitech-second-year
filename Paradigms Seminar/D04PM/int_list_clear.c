/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** int_list_clear
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void int_list_clear(int_list_t *front_ptr)
{
    int_list_t tmp = *front_ptr;
    int_list_t to_delete = NULL;

    while (tmp != NULL) {
        to_delete = tmp;
        tmp = tmp->next;
        free(to_delete);
    }
    free(tmp);
    *front_ptr = NULL;
}
