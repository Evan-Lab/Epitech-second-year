/*
** EPITECH PROJECT, 2023
** groundhog
** File description:
** test_is_number
*/

#include "groundhog.h"
#include <criterion/criterion.h>

int check_is_number(char *str);

Test(check_is_number, empty_string)
{
    char *str = "";
    int result = check_is_number(str);
    cr_assert_eq(result, 0, "Expected check_is_number('%s') to return 0", str);
}

Test(check_is_number, valid_number)
{
    char *str = "12345";
    int result = check_is_number(str);
    cr_assert_eq(result, 0, "Expected check_is_number('%s') to return 0", str);
}

Test(check_is_number, invalid_character)
{
    char *str = "12a45";
    int result = check_is_number(str);
    cr_assert_eq(result, 84, "Expected check_is_number('%s') to return 0", str);
}

Test(check_is_number, decimal_number)
{
    char *str = "12.345";
    int result = check_is_number(str);
    cr_assert_eq(result, 0, "Expected check_is_number('%s') to return 0", str);
}