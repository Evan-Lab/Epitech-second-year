/*
** EPITECH PROJECT, 2023
** RUSH2
** File description:
** char.c
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct {
    Class base;
    char x;
}   CharClass;

const Class   *Char;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (this == NULL)
        raise("this is NULL");
    if (args == NULL)
        raise("args is NULL");
    this->x = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
   (void)this;
}

static char *Char_str(CharClass *this)
{
    CharClass *yes = this;
    char *str = malloc(sizeof(char) * 50);
    snprintf(str, 50,"<Char (%c)>", yes->x);
    return str;
}

static Object *Char_add(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    if ((((CharClass*)p1)->x + ((CharClass*)p2)->x) > 127)
        raise("char is out of ascii table");
    return new(Char, ((CharClass*)p1)->x + ((CharClass*)p2)->x);
}

static Object *Char_sub(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    if ((((CharClass*)p1)->x + ((CharClass*)p2)->x) < 0)
        raise("char is out of ascii table");
    return new(Char, ((CharClass*)p1)->x - ((CharClass*)p2)->x);
}

static Object *Char_mul(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    if ((((CharClass*)p1)->x * ((CharClass*)p2)->x) > 127)
        raise("char is out of ascii table");
    return new(Char, ((CharClass*)p1)->x * ((CharClass*)p2)->x);
}

static Object *Char_div(Object *p1, Object *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("first or seconde is NULL");
    if (((CharClass*)p2)->x == 0) {
        raise("division by 0 is impossible\n");
        return NULL;
    }
    return new(Char, ((CharClass*)p1)->x / ((CharClass*)p2)->x);
}

static bool Char_eq(CharClass *first, CharClass *seconde)
{
    if (first->x == seconde->x)
        return true;
    return false;
}

static bool Char_gt(CharClass *first, CharClass *seconde)
{
    if (first->x > seconde->x)
        return true;
    return false;
}

static bool Char_lt(CharClass *first, CharClass *seconde)
{
    if (first->x < seconde->x)
        return true;
    return false;
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)Char_add,
        .__sub__ = (binary_operator_t)Char_sub,
        .__mul__ = (binary_operator_t)Char_mul,
        .__div__ = (binary_operator_t)Char_div,
        .__eq__ = (binary_comparator_t)Char_eq,
        .__gt__ = (binary_comparator_t)Char_gt,
        .__lt__ = (binary_comparator_t)Char_lt
    },
    .x = 0
};

const Class   *Char = (const Class *)&_description;
