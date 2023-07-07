/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** test_if_more_than_0
*/

#include <criterion/criterion.h>
#include "../include/panoramix.h"

int check_if_more_than_0(char **argv);

Test(check_if_more_than_0, valid_number)
{
    char *argv[5] = {"./panoramix", "1", "2", "3", "4"};
    int result = check_if_more_than_0(argv);
    cr_assert_eq(result, 0, "Expected check_if_more_than_0('%s') to return 0", argv[1]);
}

Test(check_if_more_than_0, invalid_number)
{
    char *argv[5] = {"./panoramix", "-1", "2", "3", "4"};
    int result = check_if_more_than_0(argv);
    cr_assert_eq(result, 84, "Expected check_if_more_than_0('%s') to return 0", argv[1]);
}

Test(check_if_more_than_0, invalid_number2)
{
    char *argv[5] = {"./panoramix", "1", "-2", "3", "4"};
    int result = check_if_more_than_0(argv);
    cr_assert_eq(result, 84, "Expected check_if_more_than_0('%s') to return 0", argv[1]);
}

Test(check_if_more_than_0, invalid_number3)
{
    char *argv[5] = {"./panoramix", "1", "2", "-3", "4"};
    int result = check_if_more_than_0(argv);
    cr_assert_eq(result, 84, "Expected check_if_more_than_0('%s') to return 0", argv[1]);
}

Test(check_if_more_than_0, invalid_number4)
{
    char *argv[5] = {"./panoramix", "1", "2", "3", "-4"};
    int result = check_if_more_than_0(argv);
    cr_assert_eq(result, 84, "Expected check_if_more_than_0('%s') to return 0", argv[1]);
}