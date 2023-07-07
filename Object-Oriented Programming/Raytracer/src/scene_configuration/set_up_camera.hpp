/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** set_up_camera
*/

#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include "../primitives/3D/Rectangle3D.hpp"
#include "../primitives/sphere.hpp"
#include "../primitives/plane.hpp"
#include "../Interfaces/Iprimitives.hpp"

namespace Raytracer
{
    struct Position
    {
        double x;
        double y;
        double z;
    };

    class Camera
    {
    public:
        Camera(const std::vector<std::shared_ptr<Iprimitives>> listPrimitives);
        Camera(int width, int height, Position position, Position rotation, double fieldOfView, const std::vector<std::shared_ptr<Iprimitives>> listPrimitive);
        ~Camera();

        // Getter
        Rectangle3D getScreen() const;
        int getWidth() const;
        int getHeight() const;
        double getPositionX() const;
        double getPositionY() const;
        double getPositionZ() const;
        Position getPosition() const;
        double getRotationX() const;
        double getRotationY() const;
        double getRotationZ() const;
        Position getRotation() const;
        double getFieldOfView() const;
        std::vector<std::vector<std::vector<Color>>> getDiffusion() const;
        std::vector<std::vector<Color>> getDisplay() const;

        // Setter
        void setWidth(int width);
        void setHeight(int height);
        void setPositionX(double x);
        void setPositionY(double y);
        void setPositionZ(double z);
        void setPosition(Position position);
        void setRotationX(double x);
        void setRotationY(double y);
        void setRotationZ(double z);
        void setRotation(Position rotation);
        void setFieldOfView(double fieldOfView);

    private:
        void createScreen();

        int _width;
        int _height;
        Position _position;
        Position _rotation;
        double _fieldOfView;
        std::vector<std::shared_ptr<Iprimitives>> _listPrimitive;
        std::vector<std::vector<std::vector<Color>>> _diffusion;
        std::vector<std::vector<Color>> _display;
        Rectangle3D _screen;
    };

}