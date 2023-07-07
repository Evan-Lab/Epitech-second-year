/*
** EPITECH PROJECT, 2023
** groundhog
** File description:
** groundhog
*/

#ifndef GROUNDHOG_H
    #define GROUNDHOG_H
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <math.h>
    #include <aio.h>

typedef struct groundhog_s{
    int period;
    int array_size;
    int switch_count;
    float *data;
    float g;
    float r;
    float s;
    float temp_r;
    float limit_inf;
    float limit_sup;
} groundhog_t;

int help(void);
int check_is_number(char *str);
int my_algorithm(groundhog_t *weather);
int temperature_increase_average(groundhog_t *weather);
int relative_temperature_evolution(groundhog_t *weather);
int standard_deviation(groundhog_t * weather);
int printer(groundhog_t *weather);
int print_end(groundhog_t *weather, char *str);
void calculs_caller(groundhog_t *weather);
float *remove_nb_characters(float *tab, int nb, int size);
void weirdest_values(groundhog_t *weather, float weirdest[]);
int check_values_if_not_number(char *str);
void calcul_q1_q3(groundhog_t *weather);
void error_check(groundhog_t *weather, char *str);
int check_is_number_2(char *str);

#endif //GROUNDHOG_H
