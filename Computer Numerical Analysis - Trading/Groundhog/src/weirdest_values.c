/*
** EPITECH PROJECT, 2023
** groundhog
** File description:
** weirdest_values
*/

#include <stdio.h>
#include <stdlib.h>
#include "groundhog.h"

void sort_array_ascending(groundhog_t *weather) {
    int i, j;
    float temp;

    for (i = 0; i < weather->array_size - 1; i++) {
        int min_idx = i;
        for (j = i + 1; j < weather->array_size; j++) {
            if (weather->data[j] < weather->data[min_idx]) {
                min_idx = j;
            }
        }
        temp = weather->data[min_idx];
        weather->data[min_idx] = weather->data[i];
        weather->data[i] = temp;
    }
}

float find_median(groundhog_t *weather) {
    float median;
    if (weather->array_size % 2 == 0) {
        median = (weather->data[weather->array_size / 2] + weather->data[weather->array_size / 2 - 1]) / 2.0;
    } else {
        median = weather->data[weather->array_size / 2];
    }
    return median;
}

void calculate_abs_deviation(groundhog_t *weather, float abs_deviation[]) {
    int i;
    float median = find_median(weather);
    for (i = 0; i < weather->array_size; i++) {
        abs_deviation[i] = fabs(weather->data[i] - median);
    }
}

void sort_desc(groundhog_t *weather, float abs_deviation[]) {
    int i, j;
    float temp;

    for (i = 0; i < weather->array_size - 1; i++) {
        int max_idx = i;
        for (j = i + 1; j < weather->array_size; j++) {
            if (abs_deviation[j] > abs_deviation[max_idx]) {
                max_idx = j;
            }
        }
        temp = abs_deviation[max_idx];
        abs_deviation[max_idx] = abs_deviation[i];
        abs_deviation[i] = temp;
        temp = weather->data[max_idx];
        weather->data[max_idx] = weather->data[i];
        weather->data[i] = temp;
    }
}

void weirdest_values(groundhog_t *weather, float weirdest[]) {
    int i;
    sort_array_ascending(weather);
    float abs_deviation[weather->array_size];
    calculate_abs_deviation(weather, abs_deviation);
    sort_desc(weather, abs_deviation);
    printf("5 weirdest values are [");
    for (i = 0; i < 5; i++) {
        weirdest[i] = weather->data[i];
        printf("%.1f", weirdest[i]);
        if (i != 4) {
            printf(", ");
        }
    }
    printf("]\n");
}