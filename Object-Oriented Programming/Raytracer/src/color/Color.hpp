/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-raytracer-evan.labourdette
** File description:
** Color
*/

#pragma once
namespace Raytracer {

    class Color {
    public:
        Color();
        Color(int r, int g, int b);
        ~Color();

        int getColorR() const;
        int getColorG() const;
        int getColorB() const;
        int getColorTransparency() const;

        void setColorR(int r);
        void setColorG(int g);
        void setColorB(int b);
        void setColorTransparency(int transparency);

        Color &operator=(const Color &other);

    private:
        int _r;
        int _g;
        int _b;
        int _transparency;
    };
}
