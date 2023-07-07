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
    int x;
}   IntClass;

const Class   *Int;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (this == NULL)
        raise("this is NULL");
    if (args == NULL)
        raise("args is NULL");
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
   (void)this;
}

static char *Int_str(IntClass *this)
{
    IntClass *yes = this;
    char *str = malloc(sizeof(char) * 50);
    snprintf(str, 50,"<Int (%d)>", yes->x);
    return str;
}

static Object *Int_add(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    return new(Int, ((IntClass*)p1)->x + ((IntClass*)p2)->x);
}

static Object *Int_sub(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    return new(Int, ((IntClass*)p1)->x - ((IntClass*)p2)->x);
}

static Object *Int_mul(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    return new(Int, ((IntClass*)p1)->x * ((IntClass*)p2)->x);
}

static Object *Int_div(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    if (((IntClass*)p2)->x == 0)
        raise("division by 0 is impossible\n");
    return new(Int, ((IntClass*)p1)->x / ((IntClass*)p2)->x);
}

static bool Int_eq(IntClass *first, IntClass *seconde)
{
    if (first->x == seconde->x)
        return true;
    return false;
}

static bool Int_gt(IntClass *first, IntClass *seconde)
{
    if (first->x > seconde->x)
        return true;
    return false;
}

static bool Int_lt(IntClass *first, IntClass *seconde)
{
    if (first->x < seconde->x)
        return true;
    return false;
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)Int_add,
        .__sub__ = (binary_operator_t)Int_sub,
        .__mul__ = (binary_operator_t)Int_mul,
        .__div__ = (binary_operator_t)Int_div,
        .__eq__ = (binary_comparator_t)Int_eq,
        .__gt__ = (binary_comparator_t)Int_gt,
        .__lt__ = (binary_comparator_t)Int_lt
    },
    .x = 0
};

const Class   *Int = (const Class *)&_description;
