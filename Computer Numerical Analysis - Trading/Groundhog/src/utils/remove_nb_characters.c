/*
** EPITECH PROJECT, 2023
** groundhog
** File description:
** remove_n_characters
*/

#include "groundhog.h"

float *remove_nb_characters(float *tab, int nb, int size)
{
    float *new_tab = malloc(sizeof(float) * (size - nb) + 1);
    new_tab[size - nb] = '\0';

    for (int i = nb, j = 0; i != size; i++, j++)
        new_tab[j] = tab[i];
    return new_tab;
}
