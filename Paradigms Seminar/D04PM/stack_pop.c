/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** stack_pop
*/

#include "stack.h"
#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool stack_pop(stack_t *stack_ptr)
{
    if (stack_is_empty(*stack_ptr))
        return false;
    node_t *tmp = *stack_ptr;
    *stack_ptr = tmp->next;
    free(tmp);
    return true;
}
