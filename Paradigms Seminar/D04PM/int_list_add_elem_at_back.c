/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** int_list_add_elem_at_back
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_node_t *newNode = malloc(sizeof(int_node_t));

    if (newNode == NULL)
        return false;
    newNode->value = elem;
    newNode->next = NULL;

    if (*front_ptr == NULL) {
        *front_ptr = newNode;
        return true;
    }
    int_node_t *tmp = *front_ptr;

    while (tmp->next)
        tmp = tmp->next;
    tmp->next = newNode;
    return true;
}
