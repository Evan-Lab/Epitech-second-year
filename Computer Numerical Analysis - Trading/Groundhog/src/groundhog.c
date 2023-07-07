/*
** EPITECH PROJECT, 2023
** groundhog
** File description:
** groundhog
*/

#include "groundhog.h"

void initializer(groundhog_t *weather)
{
    weather->array_size = 0;
    weather->switch_count = 0;
    weather->temp_r = 0.0;
}

void loop(groundhog_t *weather)
{
    initializer(weather);
    char *str = NULL;
    size_t size = 0;
    ssize_t read;

    while ((read = getline(&str, &size, stdin)) != -1) {
        error_check(weather, str);
        print_end(weather, str);
        weather->data[weather->array_size] = atof(str);
        if (weather->array_size == weather->period - 1)
            standard_deviation(weather);
        if (weather->array_size < weather->period) {
            printer(weather);
            weather->array_size++;
            continue;
        }
        calculs_caller(weather);
        printer(weather);
        weather->array_size++;
    }
    exit(84);
}

int my_algorithm(groundhog_t *weather)
{
    weather->data = malloc(sizeof(float) * 500);
    weather->data[499] = '\0';
    loop(weather);
    return 0;
}
