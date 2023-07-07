/*
** EPITECH PROJECT, 2023
** rush2
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../new.h"
#include "../player.h"
#include "../point.h"
#include "../vertex.h"

Test(new, new_player, .init = cr_redirect_stdout)
{
    Object *player = new(Player);
    delete(player);
}

Test(new, new_object, .init = cr_redirect_stdout)
{
    Object *point = new(Point, 42, -42);
    delete(point);
}

Test(new, new_vertex, .init = cr_redirect_stdout)
{
    Object *vertex = new(Vertex, 0, 1, 2);
    delete(vertex);
}

Test(empty, empty_vertex, .init = cr_redirect_stdout)
{
    Object *vertex = new(Vertex);
    Object *point = new(Point, 0, 0);
}

Test(new, va_new, .init = cr_redirect_stdout)
{
    Object *obj = NULL;
    va_list ap;
    Object *va_new = (NULL, &ap);
}

Test(new, new_null, .init = cr_redirect_stdout)
{
    Object *obj = NULL;
    va_list ap;
    Object *new = (NULL, &ap);
}
