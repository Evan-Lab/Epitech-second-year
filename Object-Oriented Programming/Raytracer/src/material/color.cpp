/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** flat_color
*/

#include "color.hpp"

namespace Raytracer {

    Color::Color()
    {
        this->_r = 0;
        this->_g = 0;
        this->_b = 0;
        this->_transparency = 0;
        this->_shadow = false;
    }

    Color::Color(int r, int g, int b, int transparency)
    {
        this->_r = r;
        this->_g = g;
        this->_b = b;
        this->_transparency = transparency;
        this->_shadow = false;
    }

    void Color::set_R(int r)
    {
        this->_r = r;
    }

    void Color::set_G(int g)
    {
        this->_g = g;
    }

    void Color::set_B(int b)
    {
        this->_b = b;
    }

    void Color::set_transparency(int transparency)
    {
        this->_transparency = transparency;
    }

    int Color::getR() const
    {
        return this->_r;
    }

    int Color::getG() const
    {
        return this->_g;
    }

    int Color::getB() const
    {
        return this->_b;
    }

    int Color::getTransparency() const
    {
        return this->_transparency;
    }

    void Color::setColor(int r, int g, int b)
    {
        this->_r = r;
        this->_g = g;
        this->_b = b;
    }

    Color Color::getColor() const
    {
        return *this;
    }

    void Color::setShadow(bool shadow)
    {
        _shadow = shadow;
    }

    bool Color::getShadow() const
    {
        return _shadow;
    }
}
