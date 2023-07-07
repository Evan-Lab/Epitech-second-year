/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-raytracer-evan.labourdette
** File description:
** Color
*/

#include "Color.hpp"

namespace Raytracer {

    Color::Color(int r, int g, int b)
    {
        _r = r;
        _g = g;
        _b = b;
    }

    Color::Color()
    {
        _r = 0;
        _g = 0;
        _b = 0;
    }

    Color::~Color()
    {
    }

    int Color::getColorR() const
    {
        return _r;
    }

    int Color::getColorG() const
    {
        return _g;
    }

    int Color::getColorB() const
    {
        return _b;
    }

    void Color::setColorR(int r)
    {
        _r = r;
    }

    void Color::setColorG(int g)
    {
        _g = g;
    }

    void Color::setColorB(int b)
    {
        _b = b;
    }

    void Color::setColorTransparency(int transparency)
    {
        _transparency = transparency;
    }

    Color &Color::operator=(const Color &other)
    {
        this->_r = other.getColorR();
        this->_g = other.getColorG();
        this->_b = other.getColorB();

        return *this;
    }
}
