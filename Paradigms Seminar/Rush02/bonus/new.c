/*
** EPITECH PROJECT, 2022
** rush2
** File description:
** new.c
*/
#include <stdarg.h>
#include "object.h"


Object *new(const Class *class, ...)
{
    Object *obj = NULL;
    va_list ap;
    va_start(ap, class);

    if (class == NULL){
        raise("Class is NULL");
        return NULL;
        }
    obj = malloc(class->__size__);
    if (obj == NULL){
        raise("Out of memory");
        return NULL;
    }
    memcpy(obj, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(obj, &ap);
    return (obj);
}

Object *va_new(const Class *class, va_list* ap)
{
    Object *obj = NULL;

    if (class == NULL){
        raise("Class is NULL");
        return NULL;
        }
    obj = malloc(class->__size__);
    if (obj == NULL){
        raise("Out of memory");
        return NULL;
    }
    memcpy(obj, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(obj, ap);
    return (obj);
}

void delete(Object *ptr)
{
    if (ptr == NULL)
        raise("Object is NULL");
    Class *ptr2 = ptr;
    if (ptr2->__dtor__ != NULL)
        ptr2->__dtor__(ptr);
    free(ptr2);
}