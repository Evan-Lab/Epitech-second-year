/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct {
    Class base;
    int x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (this == NULL)
        raise("this is NULL");
    if (args == NULL)
        raise("args is NULL");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
   (void)this;
}

static char *Point_str(PointClass *this)
{
    PointClass *point = this;
    char *str = malloc(sizeof(char) * 50);
    snprintf(str, 50,"<Point (%d, %d)>", point->x, point->y);
    return str;
}

static Object *Point_add(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    return new(Point, ((PointClass*)p1)->x + ((PointClass*)p2)->x,
    ((PointClass*)p1)->y + ((PointClass*)p2)->y);
}

static Object *Point_sub(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    return new(Point, ((PointClass*)p1)->x - ((PointClass*)p2)->x,
    ((PointClass*)p1)->y - ((PointClass*)p2)->y);
}

static Object *Point_mul(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    return new(Point, ((PointClass*)p1)->x * ((PointClass*)p2)->x,
    ((PointClass*)p1)->y * ((PointClass*)p2)->y);
}

static Object *Point_div(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    return new(Point, ((PointClass*)p1)->x / ((PointClass*)p2)->x,
    ((PointClass*)p1)->y / ((PointClass*)p2)->y);
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)Point_add,
        .__sub__ = (binary_operator_t)Point_sub,
        .__mul__ = (binary_operator_t)Point_mul,
        .__div__ = (binary_operator_t)Point_div,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
