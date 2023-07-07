/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** stack_top
*/

#include "stack.h"
#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void *stack_top(stack_t stack)
{
    if (stack_is_empty(stack))
        return NULL;
    return stack->value;
}
