/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** tests_is_numbe
*/

#include <criterion/criterion.h>

int is_number(char *str);

Test(is_number, empty_string)
{
    char *str = "";
    int result = is_number(str);
    cr_assert_eq(result, 0, "Expected is_number('%s') to return 0", str);
}

Test(is_number, valid_number)
{
    char *str = "12345";
    int result = is_number(str);
    cr_assert_eq(result, 1, "Expected is_number('%s') to return 1", str);
}

Test(is_number, invalid_character)
{
    char *str = "12a45";
    int result = is_number(str);
    cr_assert_eq(result, 0, "Expected is_number('%s') to return 0", str);
}

Test(is_number, decimal_number)
{
    char *str = "12.345";
    int result = is_number(str);
    cr_assert_eq(result, 0, "Expected is_number('%s') to return 0", str);
}
