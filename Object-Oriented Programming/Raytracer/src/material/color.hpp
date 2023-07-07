/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** flat_color
*/

#pragma once

namespace Raytracer {
    class Color {
        public:
            Color();
            Color(int r, int g, int b, int transparency);
            ~Color() {};

            int getR() const;
            int getG() const;
            int getB() const;
            int getTransparency() const;
            bool getShadow() const;

            void set_R(int r);
            void set_G(int g);
            void set_B(int b);
            void set_transparency(int transparency);
            void setShadow(bool shadow);

            void setColor(int r, int g, int b);
            Color getColor() const;

    private:
        int _r;
        int _g;
        int _b;
        int _transparency;
        bool _shadow;
    };
}
