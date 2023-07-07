/*
** EPITECH PROJECT, 2023
** groundhog
** File description:
** test_help
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

int help(void);

void redirect_stdout(void)
{
    cr_redirect_stdout();
}

Test(help, should_print_usage, .init = redirect_stdout)
{
    int result = help();
    cr_assert_eq(result, 0, "Expected return value 0");
}