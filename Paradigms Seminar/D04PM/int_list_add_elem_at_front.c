/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** int_list_add_elem_at_front
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_node_t *newNode = malloc(sizeof(int_node_t));
    if (newNode == NULL)
        return false;

    newNode->value = elem;
    newNode->next = *front_ptr;

    *front_ptr = newNode;

    return true;
}
