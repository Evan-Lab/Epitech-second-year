/*
** EPITECH PROJECT, 2023
** RUSH2
** File description:
** float.c
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct {
    Class base;
    float x;
}   FloatClass;

const Class   *Float;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (this == NULL)
        raise("this is NULL");
    if (args == NULL)
        raise("args is NULL");
    this->x = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
   (void)this;
}

static char *Float_str(FloatClass *this)
{
    FloatClass *yes = this;
    char *str = malloc(sizeof(char) * 50);
    snprintf(str, 50,"<Float (%f)>", yes->x);
    return str;
}

static Object *Float_add(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    return new(Float, ((FloatClass*)p1)->x + ((FloatClass*)p2)->x);
}

static Object *Float_sub(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    return new(Float, ((FloatClass*)p1)->x - ((FloatClass*)p2)->x);
}

static Object *Float_mul(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    return new(Float, ((FloatClass*)p1)->x * ((FloatClass*)p2)->x);
}

static Object *Float_div(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    if (((FloatClass*)p2)->x == 0) {
        raise("division by 0 is impossible\n");
        return NULL;
    }
    return new(Float, ((FloatClass*)p1)->x / ((FloatClass*)p2)->x);
}

static bool Float_eq(FloatClass *first, FloatClass *seconde)
{
    //FloatClass *result = new(Float, 0);

    if (first->x == seconde->x)
        return true;
    return false;
}

static bool Float_gt(FloatClass *first, FloatClass *seconde)
{
    //FloatClass *result = new(Float, 0);

    if (first->x > seconde->x)
        return true;
    return false;
}

static bool Float_lt(FloatClass *first, FloatClass *seconde)
{
    //FloatClass *result = new(Float, 0);

    if (first->x < seconde->x)
        return true;
    return false;
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)Float_add,
        .__sub__ = (binary_operator_t)Float_sub,
        .__mul__ = (binary_operator_t)Float_mul,
        .__div__ = (binary_operator_t)Float_div,
        .__eq__ = (binary_comparator_t)Float_eq,
        .__gt__ = (binary_comparator_t)Float_gt,
        .__lt__ = (binary_comparator_t)Float_lt
    },
    .x = 0
};

const Class   *Float = (const Class *)&_description;
