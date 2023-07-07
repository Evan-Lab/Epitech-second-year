/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** add_elem
*/

#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool list_add_elem_at_position(list_t *front_ptr, void *elem, unsigned int pos)
{
    node_t *newNode = malloc(sizeof(node_t));
    node_t *tmp = *front_ptr;
    if (newNode == NULL)
        return false;
    newNode->value = elem;
    newNode->next = NULL;
    if (pos == 0) {
        newNode->next = *front_ptr;
        *front_ptr = newNode;
        return true;
    }
    for (unsigned int i = 0; i < pos - 1; i++) {
        if (tmp->next == NULL)
            return false;
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    return true;
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    node_t *newNode = malloc(sizeof(node_t));

    if (newNode == NULL)
        return false;
    newNode->value = elem;
    newNode->next = NULL;

    if (*front_ptr == NULL) {
        *front_ptr = newNode;
        return true;
    }
    node_t *tmp = *front_ptr;

    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = newNode;
    return true;
}

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *newNode = malloc(sizeof(node_t));
    if (newNode == NULL)
        return false;

    newNode->value = elem;
    newNode->next = *front_ptr;

    *front_ptr = newNode;
    return true;
}
