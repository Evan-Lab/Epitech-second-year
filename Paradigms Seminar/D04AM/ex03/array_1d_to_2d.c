/*
** EPITECH PROJECT, 2023
** ex04
** File description:
** array_1d_to_2d_array
*/

#include <aio.h>
#include <stdlib.h>
#include <stdio.h>

void array_1d_to_2d (const int *array, size_t height, size_t width, int ***res)
{
    int **array_2d = malloc(sizeof(int *) * height);
    int j = 0;
    int k = 0;

    for (int i = 0; i < height; i++) {
        array_2d[i] = malloc(sizeof(int) * width);
        while (j < width) {
            array_2d[i][j] = array[k];
            j++;
            k++;
        }
        j = 0;
    }
    *res = array_2d;
}

void array_2d_free(int **array ,size_t height ,size_t width)
{
    for (int i = 0; i < height; i++)
        free(array[i]);
    free(array);
}
