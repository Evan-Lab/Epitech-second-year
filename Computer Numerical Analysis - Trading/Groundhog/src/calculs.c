/*
** EPITECH PROJECT, 2023
** groundhog
** File description:
** calculs
*/

#include "groundhog.h"

void calculs_caller(groundhog_t *weather)
{
    temperature_increase_average(weather);
    relative_temperature_evolution(weather);
    standard_deviation(weather);
}

int temperature_increase_average(groundhog_t *weather)
{
    float result = 0;
    float buff = 0;

    for (int i = 0; i < weather->period; i++) {
        buff = (weather->data[weather->array_size - i] -
            weather->data[weather->array_size - i - 1]);
        if (buff < 0)
            continue;
        result = result + (round(buff * 100) / 100);
    }
    result = result / weather->period;
    weather->g = result;
    return 0;
}

int relative_temperature_evolution(groundhog_t *weather)
{
    float result = 0;

    result = (weather->data[weather->array_size] -
        weather->data[weather->array_size - weather->period]);
    result = result / weather->data[weather->array_size - weather->period];
    result = result * 100;
    result = round(result);
    weather->r = result;
    return 0;
}

int standard_deviation(groundhog_t *weather)
{
    float mean = 0;
    float result = 0;

    for (int i = 0; i < weather->period; i++)
        mean = mean + (weather->data[weather->array_size - i]);
    mean = mean / weather->period;

    for (int i = 0; i < weather->period; i++) {
        result = result + pow((weather->data[weather->array_size - i]
            - mean), 2);
    }
    result = sqrt(result / (weather->period));
    result = round(result * 100) / 100;
    weather->s = result;
    return 0;
}
