/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct {
    Class base;
    int x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (this == NULL)
        raise("this is NULL");
    if (args == NULL)
        raise("args is NULL");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
   (void)this;
}

static char *Vertex_str(VertexClass *this)
{
    char *str = malloc(sizeof(char) * 60);
    snprintf(str, 60,"<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return str;
}

static Object *Vertex_add(Object *first, Object *seconde)
{
    if (first == NULL || seconde == NULL)
        raise("first or seconde is NULL");
    return new(Vertex, ((VertexClass*)first)->x + ((VertexClass*)seconde)->x,
    ((VertexClass*)first)->y + ((VertexClass*)seconde)->y,
    ((VertexClass*)first)->z + ((VertexClass*)seconde)->z);
}

static Object *Vertex_sub(Object *first, Object *seconde)
{
    if (first == NULL || seconde == NULL)
        raise("first or seconde is NULL");
    return new(Vertex, ((VertexClass*)first)->x - ((VertexClass*)seconde)->x,
    ((VertexClass*)first)->y - ((VertexClass*)seconde)->y,
    ((VertexClass*)first)->z - ((VertexClass*)seconde)->z);
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Vertex_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
