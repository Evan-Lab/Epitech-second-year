/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** stack_empty
*/

#include "stack.h"
#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool stack_is_empty(stack_t stack)
{
    return list_is_empty(stack);
}
