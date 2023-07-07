/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** stack_push
*/

#include "stack.h"
#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool stack_push(stack_t *stack_ptr, void *elem)
{
    return list_add_elem_at_front(stack_ptr, elem);
}
