/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** set_up_camera
*/

#include "set_up_camera.hpp"

namespace Raytracer {

    Camera::Camera(std::vector<std::shared_ptr<Iprimitives>> listPrimitive)
    {
        _width = 400;
        _height = 400;
        _position = { 0, 0, 0 };
        _rotation = { 0, 0, 0 };
        _fieldOfView = 60.0;
        _listPrimitive = listPrimitive;

        Point3D screenOrigin(0, 0, -1);
        Vector3D bottomSide(1, 0, 0);
        Vector3D leftSide(0, 1, 0);
        Rectangle3D screen(screenOrigin, bottomSide, leftSide);

        _screen = screen;
        createScreen();
    }

    Camera::Camera(int width, int height, Position position, Position rotation, double fieldOfView, std::vector<std::shared_ptr<Iprimitives>> listPrimitive)
    {
        _width = width;
        _height = height;
        _position = position;
        _rotation = rotation;
        _fieldOfView = fieldOfView;
        _listPrimitive = listPrimitive;

        Point3D screenOrigin(0, 0, -1);
        Vector3D bottomSide(1, 0, 0);
        Vector3D leftSide(0, 1, 0);
        Rectangle3D screen(screenOrigin, bottomSide, leftSide);

        _screen = screen;
        createScreen();
    }

    Camera::~Camera()
    {

    }

    int Camera::getWidth() const
    {
        return _width;
    }

    int Camera::getHeight() const
    {
        return _height;
    }

    double Camera::getPositionX() const
    {
        return _position.x;
    }

    double Camera::getPositionY() const
    {
        return _position.y;
    }

    double Camera::getPositionZ() const
    {
        return _position.z;
    }

    Position Camera::getPosition() const
    {
        return _position;
    }

    double Camera::getRotationX() const
    {
        return _rotation.x;
    }

    double Camera::getRotationY() const
    {
        return _rotation.y;
    }

    double Camera::getRotationZ() const
    {
        return _rotation.z;
    }

    Position Camera::getRotation() const
    {
        return _rotation;
    }

    double Camera::getFieldOfView() const
    {
        return _fieldOfView;
    }

    std::vector<std::vector<std::vector<Color>>> Camera::getDiffusion() const
    {
        return _diffusion;
    }

    std::vector<std::vector<Color>> Camera::getDisplay() const
    {
        return _display;
    }

    Rectangle3D Camera::getScreen() const
    {
        return _screen;
    }

    void Camera::setWidth(int width)
    {
        _width = width;
    }

    void Camera::setHeight(int height)
    {
        _height = height;
    }

    void Camera::setPositionX(double x)
    {
        _position.x = x;
    }

    void Camera::setPositionY(double y)
    {
        _position.y = y;
    }

    void Camera::setPositionZ(double z)
    {
        _position.z = z;
    }

    void Camera::setPosition(Position position)
    {
        _position = position;
    }

    void Camera::setRotationX(double x)
    {
        _rotation.x = x;
    }

    void Camera::setRotationY(double y)
    {
        _rotation.y = y;
    }

    void Camera::setRotationZ(double z)
    {
        _rotation.z = z;
    }

    void Camera::setRotation(Position rotation)
    {
        _rotation = rotation;
    }

    void Camera::setFieldOfView(double fieldOfView)
    {
        _fieldOfView = fieldOfView;
    }

    // Other

    double convertIntervalle(double value, double minValue, double maxValue, double targetMinValue, double targetMaxValue)
    {
        double range = maxValue - minValue;
        double targetRange = targetMaxValue - targetMinValue;
        double normalizedValue = (value - minValue) / range;
        double convertedValue = (normalizedValue * targetRange) + targetMinValue;

        return convertedValue;
    }

    void Camera::createScreen()
    {
        _display.resize(_width, std::vector<Color>(_height));
        Point3D cameraPosition(_position.x, _position.y, _position.z);

        for (int x = 0; x < _width; ++x) {
            for (int y = 0; y < _height; ++y) {
                double minDistance = std::numeric_limits<double>::infinity();
                for (size_t count = 0; count < _listPrimitive.size(); ++count)
                {
                    double u = static_cast<double>(x) / _width;
                    double v = static_cast<double>(y) / _height;

                    double stock_x = _listPrimitive[count].get()->getX();
                    double stock_y = _listPrimitive[count].get()->getY();

                    double convertedValueX = convertIntervalle(_listPrimitive[count].get()->getX(), -_width, _width, -5.0, 5.0);
                    double convertedValueY = convertIntervalle(_listPrimitive[count].get()->getY(), -_width, _width, -5.0, 5.0);

                    if (_listPrimitive[count].get()->getY() > 0)
                        convertedValueY = (-convertedValueY);
                    else
                        convertedValueY = std::abs(convertedValueY);

                    _listPrimitive[count].get()->setX(convertedValueX);
                    _listPrimitive[count].get()->setY(convertedValueY);

                    Point3D screenPoint = _screen.pointAt(u, v);
                    Vector3D direction((screenPoint - cameraPosition).getX(), (screenPoint - cameraPosition).getY(), (screenPoint - cameraPosition).getZ());
                    direction.normalize();

                    Ray ray(cameraPosition, direction, 0, 1000);

                    double t = 0.0;
                    if (_listPrimitive[count].get()->hits(ray, t)) {
                        t = _listPrimitive[count]->getDistance();
                        if (t < minDistance) {
                            minDistance = _listPrimitive[count]->getDistance();
                            _display[x][y] = _listPrimitive[count].get()->getColor();
                        }
                    }
                    _listPrimitive[count].get()->setX(stock_x);
                    _listPrimitive[count].get()->setY(stock_y);
                }
            }
        }
    }

}