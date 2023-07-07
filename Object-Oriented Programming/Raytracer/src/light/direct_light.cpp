/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** directional_light
*/

#include "direct_light.hpp"

#include <iostream>
#include <algorithm>

namespace Raytracer
{

    Direct_light::Direct_light()
    {
        _direct_light = 0;
        _position.setX(3);
        _position.setY(3);
        _position.setZ(0);

    }

    Direct_light::Direct_light(int intensity) : _intensity(intensity)
    {
    }

    Direct_light::~Direct_light()
    {
    }

    void Direct_light::set_direct_light(int direct_light)
    {
        _direct_light = direct_light;
    }

    int Direct_light::get_direct_light() const
    {
        return _direct_light;
    }

    void Direct_light::set_intensity(int intensity)
    {
        _intensity = intensity;
    }

    int Direct_light::get_intensity() const
    {
        return _intensity;
    }

    void Direct_light::set_distance(double distance)
    {
        _distance = distance;
    }

    double Direct_light::get_distance() const
    {
        return _distance;
    }

    void Direct_light::set_position(Point3D position)
    {
        _position = position;
    }

    Point3D Direct_light::get_position() const
    {
        return _position;
    }

    Color Direct_light::darkenColor(Color color, double factor)
    {
        color.set_R(static_cast<int>(color.getR() * factor));
        color.set_G(static_cast<int>(color.getG() * factor));
        color.set_B(static_cast<int>(color.getB() * factor));
        return color;
    }

    void Direct_light::show_light(int color, std::vector<std::vector<Color>> &buffer, int x1, int y1, int x2, int y2)
    {
        int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
        int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
        int err = (dx > dy ? dx : -dy) / 2, e2;

        while (true)
        {
            if ((size_t)x1 < buffer.size() && (size_t)y1 < buffer[0].size())
            {
                int r = std::min(color * _intensity / 255, 255);
                int g = std::min(color * _intensity / 255, 255);
                int b = std::min(color * _intensity / 255, 255);
                buffer[x1][y1].set_R(r);
                buffer[x1][y1].set_G(g);
                buffer[x1][y1].set_B(b);
            }

            if (x1 == x2 && y1 == y2)
                break;

            e2 = err;
            if (e2 > -dx)
            {
                err -= dy;
                x1 += sx;
            }
            if (e2 < dy)
            {
                err += dx;
                y1 += sy;
            }
        }
    }

    bool Direct_light::shadow(const std::vector<std::shared_ptr<Iprimitives>> &spheres, int x, int y)
    {
        Raytracer::Ray shadowRay;
        shadowRay.setOrigin(Point3D(x, y, 0));
        shadowRay.setDirection(Vector3D(_position.getX() - x, _position.getY() - y, _position.getZ() - 0));

        for (const auto &sphere : spheres)
        {
            double t = 0;
            if (sphere->hits(shadowRay, t))
            {
                return true;
            }
        }
        return false;
    }

    void Direct_light::show_shadow(const std::vector<std::shared_ptr<Iprimitives>> &spheres, std::vector<std::vector<Color>> &buffer, int x1, int y1, int x2, int y2)
    {
        for (int y = y1; y < y2; y++)
        {
            for (int x = x1; x < x2; x++)
            {
                bool is_shadowed = shadow(spheres, x, y);

                if (is_shadowed)
                {
                    buffer[y][x] = Color(255, 0, 0, 255);
                } else
                {
                    buffer[y][x] = Color(126, 45, 210, 255);
                }
            }
        }
    }

    double Direct_light::convertIntervalle(double value, double minValue, double maxValue, double targetMinValue, double targetMaxValue)
    {
        double range = maxValue - minValue;
        double targetRange = targetMaxValue - targetMinValue;
        double normalizedValue = (value - minValue) / range;
        double convertedValue = (normalizedValue * targetRange) + targetMinValue;

        return convertedValue;
    }

    std::vector<Index> Direct_light::getListIntersection(Point3D &origin, double x, double y, std::vector<std::shared_ptr<Iprimitives>> primitives, std::vector<std::vector<Color>> display, Rectangle3D screen, std::vector<Point3D> listIntersection)
    {
        double width = display.size();
        double height = display[0].size();
        std::vector<Index> listIndex;

        Point3D test = origin;

        for (; x < width; ++x)
        {
            for (; y < height; ++y)
            {
                double minDistance = std::numeric_limits<double>::infinity();
                for (size_t count = 0; count < primitives.size(); ++count)
                {
                    double u = static_cast<double>(x) / width;
                    double v = static_cast<double>(y) / height;

                    double stock_x = primitives[count]->getX();
                    double stock_y = primitives[count]->getY();

                    double convertedValueX = convertIntervalle(primitives[count]->getX(), -width, width, -5.0, 5.0);
                    double convertedValueY = convertIntervalle(primitives[count]->getY(), -height, height, -5.0, 5.0);

                    if (primitives[count]->getY() > 0)
                        convertedValueY = (-convertedValueY);
                    else
                        convertedValueY = std::abs(convertedValueY);

                    primitives[count]->setX(convertedValueX);
                    primitives[count]->setY(convertedValueY);

                    Point3D screenPoint = screen.pointAt(u, v);
                    Vector3D direction((screenPoint - _position).getX(), (screenPoint - _position).getY(), (screenPoint - _position).getZ());
                    direction.normalize();

                    Ray ray(test, direction, 0, 1000);

                    double t = 0.0;
                    if (primitives[count]->hits(ray, t))
                    {
                        t = primitives[count]->getDistance();
                        Point3D intersection = primitives[count]->getIntersection(ray);
                        listIntersection.push_back(intersection);
                        test = intersection;
                        if (listIntersection.size() > 1)
                        {
                            Index index;
                            index.x = x;
                            index.y = y;

                            listIndex.push_back(index);
                        }
                    }
                    primitives[count]->setX(stock_x);
                    primitives[count]->setY(stock_y);
                }
            }
        }

        return listIndex;
    }

    std::vector<Index> Direct_light::remove_doublon(std::vector<Index> &listIndex)
    {
        std::sort(listIndex.begin(), listIndex.end(), [](const Index &a, const Index &b) {
            return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y));
            });

        auto newEnd = std::unique(listIndex.begin(), listIndex.end(), [](const Index &a, const Index &b) {
            return (a.x == b.x) && (a.y == b.y);
            });

        listIndex.erase(newEnd, listIndex.end());
        return listIndex;
    }

    std::vector<std::vector<Color>> Direct_light::diffuse_light(std::vector<std::shared_ptr<Iprimitives>> primitives, std::vector<std::vector<Color>> display, Rectangle3D screen)
    {
        double width = display.size();
        double height = display[0].size();
        std::vector<Index> listIndex;

        for (double x = 0; x < width; ++x)
        {
            for (double y = 0; y < height; ++y)
            {
                double minDistance = std::numeric_limits<double>::infinity();
                for (size_t count = 0; count < primitives.size(); ++count)
                {
                    double u = static_cast<double>(x) / width;
                    double v = static_cast<double>(y) / height;

                    double stock_x = primitives[count]->getX();
                    double stock_y = primitives[count]->getY();

                    double convertedValueX = convertIntervalle(primitives[count]->getX(), -width, width, -5.0, 5.0);
                    double convertedValueY = convertIntervalle(primitives[count]->getY(), -height, height, -5.0, 5.0);

                    if (primitives[count]->getY() > 0)
                        convertedValueY = (-convertedValueY);
                    else
                        convertedValueY = std::abs(convertedValueY);

                    primitives[count]->setX(convertedValueX);
                    primitives[count]->setY(convertedValueY);

                    Point3D screenPoint = screen.pointAt(u, v);
                    Vector3D direction((screenPoint - _position).getX(), (screenPoint - _position).getY(), (screenPoint - _position).getZ());
                    direction.normalize();

                    Ray ray(_position, direction, 0, 1000);

                    double t = 0.0;
                    if (primitives[count]->hits(ray, t))
                    {
                        t = primitives[count]->getDistance();
                        Point3D intersection = primitives[count]->getIntersection(ray);
                        std::vector<Point3D> inter;
                        std::vector<Index> stock;
                        stock = getListIntersection(intersection, x, y, primitives, display, screen, inter);
                        listIndex.insert(listIndex.end(), stock.begin(), stock.end());
                        std::cout << "X: " << x << " Y: " << y << " INTER: " << inter.size() << std::endl;
                    }
                    primitives[count]->setX(stock_x);
                    primitives[count]->setY(stock_y);
                }
            }
        }
        listIndex = remove_doublon(listIndex);
        for (size_t count = 0; count < listIndex.size(); ++count) {
            int x = listIndex[count].x;
            int y = listIndex[count].y;
            Color newColor(display[x][y].getR(), display[x][y].getG(), display[x][y].getB(), 255);

            display[x][y].set_R(darkenColor(newColor, 0.7).getR());
            display[x][y].set_G(darkenColor(newColor, 0.7).getG());
            display[x][y].set_B(darkenColor(newColor, 0.7).getB());
        }
        return display;
    }
}