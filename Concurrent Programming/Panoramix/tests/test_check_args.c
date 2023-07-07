/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** test_check_args
*/

#include <criterion/criterion.h>
#include "../include/panoramix.h"

int check_args(int argc, char **argv);

Test(check_args, valid_args)
{
    char *argv[5] = {"./panoramix", "1", "2", "3", "4"};
    int argc = 5;
    int result = check_args(argc, argv);
    cr_assert_eq(result, 0, "Expected check_args('%s') to return 0", argv[1]);
}

Test(check_args, invalid_args)
{
    char *argv[5] = {"./panoramix", "1", "2", "3", "4"};
    int argc = 4;
    int result = check_args(argc, argv);
    cr_assert_eq(result, 84, "Expected check_args('%s') to return 0", argv[1]);
}
