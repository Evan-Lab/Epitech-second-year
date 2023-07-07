/*
** EPITECH PROJECT, 2023
** groundhog
** File description:
** test_temperature
*/

#include "groundhog.h"
#include <assert.h>
#include <criterion/criterion.h>

int temperature_increase_average(groundhog_t *weather);
int relative_temperature_evolution(groundhog_t *weather);
int standard_deviation(groundhog_t * weather);

Test(temperature_increase_average, positive_values)
{
    groundhog_t weather;
    float data[] = {12.5, 13.2, 15.1, 16.4, 18.2, 21.5};
    weather.array_size = 5;
    weather.period = 3;
    weather.data = data;
    temperature_increase_average(&weather);
    cr_assert_float_eq(weather.g, 2.13, 0.01);
}

Test(relative_temperature_evolution, positive_values)
{
    groundhog_t weather;
    float data[] = {12.5, 13.2, 15.1, 16.4, 18.2, 21.5};
    weather.array_size = 5;
    weather.period = 3;
    weather.data = data;
    relative_temperature_evolution(&weather);
    cr_assert_float_eq(weather.r, 42.00, 0.01);
}

Test(standard_deviation, positive_values)
{
    groundhog_t weather;
    float data[] = {12.5, 13.2, 15.1, 16.4, 18.2, 21.5};
    weather.array_size = 5;
    weather.period = 3;
    weather.data = data;
    standard_deviation(&weather);
    cr_assert_float_eq(weather.s, 2.11, 0.01);
}