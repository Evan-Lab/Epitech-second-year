/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** directional_light
*/

#pragma once

#include "../Interfaces/Ilight.hpp"
#include "../material/color.hpp"
#include "../primitives/3D/Vector3D.hpp"
#include "../primitives/3D/Ray.hpp"
#include "../primitives/sphere.hpp"
#include "../primitives/3D/Point3D.hpp"
#include "../primitives/3D/Rectangle3D.hpp"

#include <vector>
#include <memory>

namespace Raytracer {

    struct Index {
        int x;
        int y;
    };
    class Direct_light : public Ilight {
    public:
        Direct_light();
        Direct_light(int direct_light);
        ~Direct_light();

        void set_direct_light(int direct_light);
        void set_intensity(int intensity);
        void set_distance(double distance);
        void set_position(Point3D position);

        int get_direct_light() const;
        int get_intensity() const;
        double get_distance() const;
        Point3D get_position() const;

        void show_light(int color, std::vector<std::vector<Color>> &buffer, int x1, int y1, int x2, int y2);
        bool shadow(const std::vector<std::shared_ptr<Raytracer::Iprimitives>> &spheres, int x, int y);
        void show_shadow(const std::vector<std::shared_ptr<Raytracer::Iprimitives>> &spheres, std::vector<std::vector<Color>> &buffer, int x1, int y1, int x2, int y2);

        Color darkenColor(Color color, double factor);

        std::vector<std::vector<Color>> diffuse_light(std::vector<std::shared_ptr<Iprimitives>> primitives, std::vector<std::vector<Color>> display, Rectangle3D screen);
        std::vector<Index> getListIntersection(Point3D &origin, double x, double y, std::vector<std::shared_ptr<Iprimitives>> primitives, std::vector<std::vector<Color>> display, Rectangle3D screen, std::vector<Point3D> listIntersection);
        double convertIntervalle(double value, double minValue, double maxValue, double targetMinValue, double targetMaxValue);

        std::vector<Index> remove_doublon(std::vector<Index> &listIndex);

    private:
        int _direct_light;
        int _intensity;
        double _distance;
        Point3D _position;
    };
}
