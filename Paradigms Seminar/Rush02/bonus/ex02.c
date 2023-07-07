/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercise 02
*/

#include <stdio.h>
#include "new.h"
#include "point.h"
#include "vertex.h"

int         main(void)
{
    Object  *point = new(Point, 42, -42);
    Object  *vertex = new(Vertex, 0, 1, 2);

    char *_point = str(point);
    char *_vertex = str(vertex);

    printf("point = %s\\n", _point);
    printf("vertex = %s\\n", _vertex);

    free(_point);
    free(_vertex);

    delete(point);
    delete(vertex);
    return (0);
}
