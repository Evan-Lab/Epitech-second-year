/*
** EPITECH PROJECT, 2023
** day13
** File description:
** Algorithme
*/

#pragma once

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T max(T a, T b)
{
    if (b < a) return a;
    else return b;
}

template <typename T>
T min(T a, T b)
{
    if (a < b) return a;
    else return b;
}

template <typename T>
T clamp(T value, T min, T max)
{
    if (value < min) {
        return min;
    } else if (max < value) {
        return max;
    } else {
        return value;
    }
}