/*
** EPITECH PROJECT, 2023
** groundhog
** File description:
** printer
*/

#include "groundhog.h"
#include <stdlib.h>

int print_end(groundhog_t *weather, char *str)
{
    if (strcmp(str, "STOP\n") == 0) {
        float weirdest[5];
        printf("Global tendency switched %d times\n", weather->switch_count);
        weirdest_values(weather, weirdest);
        //calcul_q1_q3(weather);
        exit(0);
    }
    return 0;
}

int print_case_switch_occurs(groundhog_t *weather)
{
    if (weather->temp_r != 0.0) {
        if (abs((int)weather->temp_r + (int)weather->r) != abs((int)weather->temp_r) + abs((int)weather->r)) {
            printf("g=%.2f\t\tr=%.0f%%\t\ts=%.2f\t\ta switch occurs\n",
                weather->g, weather->r, weather->s);
            weather->switch_count++;
        } else
            printf("g=%.2f\t\tr=%.0f%%\t\ts=%.2f\n",
                weather->g, weather->r, weather->s);
    } else
        printf("g=%.2f\t\tr=%.0f%%\t\ts=%.2f\n",
            weather->g, weather->r, weather->s);
    weather->temp_r = weather->r;
    return 0;
}

int printer(groundhog_t *weather)
{
    if (weather->array_size == weather->period - 1)
        printf("g=nan\t\tr=nan%%\t\ts=%.2f\n", weather->s);
    else if (weather->array_size < weather->period - 1)
        printf("g=nan\t\tr=nan%%\t\ts=nan\n");
    else
        print_case_switch_occurs(weather);
    return 0;
}
