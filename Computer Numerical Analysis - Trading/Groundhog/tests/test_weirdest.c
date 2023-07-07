/*
** EPITECH PROJECT, 2023
** groundhog
** File description:
** test_weirdest
*/

#include "groundhog.h"
#include <criterion/criterion.h>

void sort_array_ascending(groundhog_t *weather);
float find_median(groundhog_t *weather);
void calculate_abs_deviation(groundhog_t *weather, float abs_deviation[]);
void sort_desc(groundhog_t *weather, float abs_deviation[]);
void weirdest_values(groundhog_t *weather, float weirdest[]);

Test(sort_array_ascending, positive_values)
{
    groundhog_t weather;
    float data[] = {12.5, 13.2, 15.1, 16.4, 18.2, 21.5};
    weather.array_size = 6;
    weather.data = data;
    sort_array_ascending(&weather);
    cr_assert_float_eq(weather.data[0], 12.5, 0.01);
    cr_assert_float_eq(weather.data[1], 13.2, 0.01);
    cr_assert_float_eq(weather.data[2], 15.1, 0.01);
    cr_assert_float_eq(weather.data[3], 16.4, 0.01);
    cr_assert_float_eq(weather.data[4], 18.2, 0.01);
    cr_assert_float_eq(weather.data[5], 21.5, 0.01);
}

Test(find_median, positive_values)
{
    groundhog_t weather;
    float data[] = {12.5, 13.2, 15.1, 16.4, 18.2, 21.5};
    weather.array_size = 6;
    weather.data = data;
    float median = find_median(&weather);
    cr_assert_float_eq(median, 15.75, 0.01);
}