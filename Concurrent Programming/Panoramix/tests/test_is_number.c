/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** test_is_number
*/

#include <criterion/criterion.h>
#include "../include/panoramix.h"

int check_if_number(char *str);

Test(check_if_number, empty_string)
{
    char *str = "";
    int result = check_if_number(str);
    cr_assert_eq(result, 0, "Expected check_if_number('%s') to return 0", str);
}

Test(check_if_number, valid_number)
{
    char *str = "12345";
    int result = check_if_number(str);
    cr_assert_eq(result, 0, "Expected check_if_number('%s') to return 0", str);
}

Test(check_if_number, invalid_character)
{
    char *str = "12a45";
    int result = check_if_number(str);
    cr_assert_eq(result, 84, "Expected check_if_number('%s') to return 0", str);
}