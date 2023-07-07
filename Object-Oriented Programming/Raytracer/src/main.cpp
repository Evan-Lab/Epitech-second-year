/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** main
*/

#include "ppm/ppm.hpp"
#include "light/direct_light.hpp"
#include "scene_configuration/set_up_camera.hpp"

#include <iostream>
#include <cstring>
#include <memory>


namespace {

    int help_usage(int argc, char **argv)
    {
        if (argc == 2 && std::strcmp(argv[1], "--help") == 0) {
            std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
            std::cout << "  SCENE_FILE: scene configuration" << std::endl;
        }
        return 0;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        help_usage(argc, argv);
    else {
        Raytracer::Color color(0, 0, 255, 0);
        Raytracer::Point3D center(0, 0, -10);
        std::shared_ptr<Raytracer::Sphere> sphere = std::make_shared<Raytracer::Sphere>(center, 2, color);

        Raytracer::Color color2(0, 255, 0, 0);
        Raytracer::Point3D center2(650, 650, -10);
        std::shared_ptr<Raytracer::Sphere> sphere2 = std::make_shared<Raytracer::Sphere>(center2, 1, color2);

        Raytracer::Color color_plan(255, 0, 0, 255);
        Raytracer::Point3D origin(0, 0, -15);
        Raytracer::Vector3D bottomSide(10, 0, 0);
        Raytracer::Vector3D leftSide(0, 10, -50);
        Raytracer::Direct_light light(255);

        std::shared_ptr<Raytracer::Plane> plane = std::make_shared<Raytracer::Plane>(origin, bottomSide, leftSide, color_plan);
        std::vector<Raytracer::Direct_light> vect2;
        std::vector<std::shared_ptr<Raytracer::Iprimitives>> vect;

        vect.push_back(sphere);
        vect.push_back(sphere2);
        vect.push_back(plane);
        vect2.push_back(light);

        Raytracer::Camera camera(vect);
        Raytracer::Ppm Ppm(camera.getDisplay());
        std::vector<std::vector<Raytracer::Color>> image = camera.getDisplay();
        Raytracer::Point3D posLight(light.get_position());
        image = light.diffuse_light(vect, image, camera.getScreen());
        Raytracer::Ppm Ppm2(image);
    }
    return 0;
}