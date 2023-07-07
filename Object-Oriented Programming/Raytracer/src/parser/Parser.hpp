/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-raytracer-evan.labourdette
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <stdlib.h>
#include <libconfig.h++>
#include <vector>

namespace Raytracer {
    struct Position
    {
        int x;
        int y;
        int z;
    };

    struct Color
    {
        int r;
        int g;
        int b;
    };

    struct Figures
    {
        struct Position _position;
        struct Color _color;
        int size;
    };

    struct Planes
    {
        std::string _axis;
        int _position;
        struct Color _color;
    };

    struct Primitives
    {
        std::string _name;
        std::vector<struct Figures> _listFigure;
        std::vector<struct Planes> _listPlane;
    };

    struct Lights
    {
        double _ambient;
        double _diffuse;
        std::vector<struct Position> _listPoint;
    };

    struct Camera
    {
        int _width;
        int _height;
        struct Position _position;
        struct Position _rotation;
        double _fieldOfView;
    };

    class Parser {
    public:
        // Ctor & Dtor
        Parser(std::string filepath);
        ~Parser();

        // Getter
        std::vector<struct Primitives> getPrimitives() const;
        std::vector<struct Lights> getLights() const;
        struct Camera getCameraConfig() const;

        // Setter
        void setPrimitive(struct Primitives primitives);
        void setLights(struct Lights lights);
        void setCamera(struct Camera camera);

    private:
        libconfig::Config _config;
        std::vector<struct Primitives> _listPrimitives;
        std::vector<struct Lights> _lightsConfig;
        struct Camera _cameraConfig;

        // Parser
        void parseSphere(const libconfig::Setting &part, struct Primitives *prim);
        void parsePlane(const libconfig::Setting &part, struct Primitives *prim);


        using ParseFunctionPtr = void (Parser:: *)(const libconfig::Setting &part, Primitives *prim);
        struct PrimitivesFunction {
            std::string name;
            ParseFunctionPtr function;
        };

        PrimitivesFunction primitivesFunctions[2] = {
            {"spheres", &Raytracer::Parser::parseSphere},
            {"planes", &Raytracer::Parser::parsePlane}
        };

        void parseInfoCamera();
        void parseInfoLights();
        void parseInfoPrimitives();
    };
}

#endif /* !PARSER_HPP_ */
