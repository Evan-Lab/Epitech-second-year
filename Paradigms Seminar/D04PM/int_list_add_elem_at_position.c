/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** int_list_add_elem_at_position
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem,
unsigned int position)
{
    unsigned int len = int_list_get_size(*front_ptr);
    if (position == 0)
        return int_list_add_elem_at_front(front_ptr, elem);
    if (position > len)
        return false;

    int_node_t *newNode = malloc(sizeof(int_node_t *));
    if (newNode == NULL)
        return false;
    newNode->value = elem;

    for (unsigned int i = 0; (*front_ptr)->next != NULL;
    *front_ptr = (*front_ptr)->next) {
        *front_ptr = (*front_ptr)->next;
        if (i == len) {
            newNode->next = (*front_ptr)->next;
            *front_ptr = newNode;
        }
    }
    return true;
}
