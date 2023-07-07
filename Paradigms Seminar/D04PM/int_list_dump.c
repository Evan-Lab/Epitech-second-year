/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** int_list_dump
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void int_list_dump(int_list_t list)
{
    for (; list != NULL; list = list->next) {
        printf("%d\n", list->value);
    }
}
