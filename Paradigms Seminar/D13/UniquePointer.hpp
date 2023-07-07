/*
** EPITECH PROJECT, 2023
** day13
** File description:
** UniquePointer
*/

#pragma once
#include <iostream>

template <typename Type>
class UniquePointer {
public:
    Type *ch;
    UniquePointer(Type *ptr = nullptr): ch(ptr)
    {
    }
    ~UniquePointer()
    {
        delete ch;
    }
    UniquePointer(UniquePointer &&other)
    {
        ch = other.ch;
        other.ch = nullptr;
    }
    UniquePointer &operator=(UniquePointer &&other)
    {
        if (this != &other) {
            delete ch;
            ch = other.ch;
            other.ch = nullptr;
        }
        return *this;
    }
    UniquePointer(const UniquePointer &) = delete;
    UniquePointer &operator=(const UniquePointer &) = delete;
    void reset()
    {
        delete ch;
        ch = nullptr;
    }
    Type *get()
    {
        return ch;
    }
    Type *operator->()
    {
        return ch;
    }
    Type &operator*()
    {
        return *ch;
    }
};