/*
** EPITECH PROJECT, 2023
** day13
** File description:
** Array
*/

#pragma once
#include <cstddef>
#include <functional>
#include <ostream>

template <typename Type, std::size_t Size>
class Array {

public:
    Array() {}
    Type data[Size];

    Type &operator[](std::size_t pos)
    {
        if (pos >= Size) {
            throw std::out_of_range("Out of range");
        }
        return data[pos];
    }

    const Type &operator[](std::size_t pos) const
    {
        if (pos >= Size) {
            throw std::out_of_range("Out of range");
        }
        return data[pos];
    }

    std::size_t size() const
    {
        return Size;
    }

    void forEach(const std::function<void(const Type &)> &task) const
    {
        for (std::size_t i = 0; i < Size; ++i) {
            task(data[i]);
        }
    }

    template <typename U>
    Array<U, Size> convert(const std::function<U(const Type &)> &converter) const
    {
        Array<U, Size> result;
        for (std::size_t i = 0; i < Size; i++) {
            result[i] = converter(data[i]);
        }
        return result;
    }
};

template <typename Type, std::size_t Size>
std::ostream &operator<<(std::ostream &os, const Array<Type, Size> &array)
{
    os << "[";
    for (std::size_t i = 0; i < Size; ++i) {
        os << array.data[i];
        if (i != Size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}