/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** test_take_words
*/

#include <criterion/criterion.h>

char *take_first_word(char *str);
char *take_rest(char *str, int nb);

Test(take_first_word, all_uppercase)
{
    char *str = "HELLO WORLD";
    char *result = take_first_word(str);
    cr_assert_str_eq(result, "HELLO", "Expected take_first_word('%s') to return 'HELLO'", str);
    free(result);
}

Test(take_first_word, no_uppercase)
{
    char *str = "hello world";
    char *result = take_first_word(str);
    cr_assert_str_empty(result, "Expected take_first_word('%s') to return an empty string", str);
    free(result);
}

/////////////////////////////////////////////////////////

Test(take_rest, returns_null_for_null_input)
{
    char *result = take_rest(NULL, 0);
    cr_assert_null(result, "Expected NULL but got %p", result);
}

Test(take_rest, returns_empty_string_for_nb_greater_than_or_equal_to_string_length)
{
    char *result = take_rest("Hello, world", 50);
    cr_assert_str_empty(result, "Expected empty string but got \"%s\"", result);

    result = take_rest("Hello, world", 13);
    cr_assert_str_empty(result, "Expected empty string but got \"%s\"", result);
}

Test(take_rest, returns_correct_substring_for_valid_input)
{
    char *result = take_rest("Hello, world", 5);
    cr_assert_str_eq(result, "world", "Expected \"world!\" but got \"%s\"", result);
    free(result);
}

