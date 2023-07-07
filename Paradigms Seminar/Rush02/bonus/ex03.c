/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 03
*/

#include <stdio.h>
#include "new.h"
#include "point.h"
#include "vertex.h"
#include "float.h"
#include "char.h"
#include "int.h"

void compareAndDivide ( Object *a , Object * b )
{
if ( gt (a , b ) )
printf ("a > b\n") ;
else if ( lt (a , b ) )
printf (" a < b\n") ;
else
printf (" a == b\n") ;
printf (" b / a =%s\n" , str ( division (b , a ) ) ) ;
}

int main(void)
{

    Object  *p5 = new(Int, 12);
    Object  *p6 = new(Int, 1);
    compareAndDivide(p5, p6);

    printf("%s + %s = %s\n", str(p5), str(p6), str(addition(p5, p6)));
    printf("%s - %s = %s\n", str(p5), str(p6), str(subtraction(p5, p6)));
    printf("%s * %s = %s\n", str(p5), str(p6), str(multiplication(p5, p6)));
    printf("%s / %s = %s\n", str(p5), str(p6), str(division(p5, p6)));
    printf("%s == %s = %d\n", str(p5), str(p6), (eq(p5, p6)));
    printf("%s > %s = %d\n", str(p5), str(p6), (gt(p5, p6)));
    printf("%s < %s = %d\n-------------------------------\n", str(p5), str(p6), (lt(p5, p6)));


    Object  *p1 = new(Float, 12.0);
    Object  *p2 = new(Float, 1.0);
    compareAndDivide(p1, p2);

    printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
    printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));
    printf("%s * %s = %s\n", str(p1), str(p2), str(multiplication(p1, p2)));
    printf("%s / %s = %s\n", str(p1), str(p2), str(division(p1, p2)));
    printf("%s == %s = %d\n", str(p1), str(p2), (eq(p1, p2)));
    printf("%s > %s = %d\n", str(p1), str(p2), (gt(p1, p2)));
    printf("%s < %s = %d\n-------------------------------\n", str(p1), str(p2), (lt(p1, p2)));

    Object  *p3 = new(Char, '1');6.0°C  


    Object  *p4 = new(Char, '0');
    compareAndDivide(p3, p4);

    printf("%s + %s = %s\n", str(p3), str(p4), str(addition(p3, p4)));
    printf("%s - %s = %s\n", str(p3), str(p4), str(subtraction(p3, p4)));
    printf("%s * %s = %s\n", str(p3), str(p4), str(multiplication(p3, p4)));
    printf("%s / %s = %s\n", str(p3), str(p4), str(division(p3, p4)));
    printf("%s == %s = %d\n", str(p3), str(p4), (eq(p3, p4)));
    printf("%s > %s = %d\n", str(p3), str(p4), (gt(p3, p4)));
    printf("%s < %s = %d\n-------------------------------\n", str(p3), str(p4), (lt(p3, p4)));

    return (0);
}
