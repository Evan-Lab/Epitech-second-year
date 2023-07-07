/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-raytracer-evan.labourdette
** File description:
** Parser
*/

#include "Parser.hpp"

// ---------- Ctor & Dtor --------------

Raytracer::Parser::Parser(std::string filepath)
{
    try {
        _config.readFile(filepath.c_str());
    } catch (libconfig::FileIOException &e) {
        std::cerr << "[FileIOException] Could not read \"" << filepath << "\"" << std::endl;
        throw std::runtime_error(e.what());
    } catch (libconfig::ParseException &e) {
        std::cerr << "[ParseException] Parse error at " << e.getFile() << ":" << e.getLine() << " - " << e.getError() << std::endl;
        throw std::runtime_error(e.getError());
    }
    parseInfoCamera();
    parseInfoLights();
    parseInfoPrimitives();
}

Raytracer::Parser::~Parser()
{
}

// ---------- Getter --------------

std::vector<struct Raytracer::Primitives> Raytracer::Parser::getPrimitives() const
{
    return _listPrimitives;
}

std::vector<struct Raytracer::Lights> Raytracer::Parser::getLights() const
{
    return _lightsConfig;
}

struct Raytracer::Camera Raytracer::Parser::getCameraConfig() const
{
    return _cameraConfig;
}

// ---------- Setter --------------

void Raytracer::Parser::setPrimitive(struct Raytracer::Primitives primitives)
{
    _listPrimitives.push_back(primitives);
}

void Raytracer::Parser::setLights(struct Raytracer::Lights lights)
{
    _lightsConfig.push_back(lights);
}

void Raytracer::Parser::setCamera(struct Raytracer::Camera camera)
{
    _cameraConfig = camera;
}

// ---------- Parser --------------


void Raytracer::Parser::parseInfoCamera()
{
    try {
        _cameraConfig._height = _config.lookup("camera.resolution.height");
        _cameraConfig._width = _config.lookup("camera.resolution.width");

        _cameraConfig._position.x = _config.lookup("camera.position.x");
        _cameraConfig._position.y = _config.lookup("camera.position.y");
        _cameraConfig._position.z = _config.lookup("camera.position.z");
    
        _cameraConfig._rotation.x = _config.lookup("camera.rotation.x");
        _cameraConfig._rotation.y = _config.lookup("camera.rotation.y");
        _cameraConfig._rotation.z = _config.lookup("camera.rotation.z");

        _cameraConfig._fieldOfView = _config.lookup("camera.fieldOfView");
    } catch (libconfig::SettingNotFoundException &e) {
        std::cerr << "[SettingsException] " << e.getPath() << " not found" << std::endl;
        throw std::runtime_error(e.what());
    }
}

void Raytracer::Parser::parseInfoLights()
{
    struct Lights lights;

    try {
        lights._ambient = _config.lookup("lights.ambient");
        lights._diffuse = _config.lookup("lights.diffuse");
        const libconfig::Setting &root = _config.getRoot();
        const libconfig::Setting &lightsPart = root["lights"];
        const libconfig::Setting &point = lightsPart["point"];

        for (int i = 0; i < point.getLength(); ++i) {
            const libconfig::Setting &p = point[i];
            struct Raytracer::Position pos;
            p.lookupValue("x", pos.x);
            p.lookupValue("y", pos.y);
            p.lookupValue("z", pos.z);
            lights._listPoint.push_back(pos);
        }
    } catch (libconfig::SettingNotFoundException &e) {
        std::cerr << "[SettingsException] " << e.getPath() << "not found" << std::endl;
        throw std::runtime_error(e.what());
    }
    setLights(lights);
}

void Raytracer::Parser::parseSphere(const libconfig::Setting &part, struct Raytracer::Primitives *prim)
{
    Raytracer::Figures newFigure;

    try {
        for (int i = 0; i < part.getLength(); ++i) {
            const libconfig::Setting &p = part[i];

            // Sphere Position
            if (!p.lookupValue("x", newFigure._position.x))
                throw std::runtime_error("Missing 'x' value for sphere.");
            if (!p.lookupValue("y", newFigure._position.y))
                throw std::runtime_error("Missing 'y' value for sphere.");
            if (!p.lookupValue("z", newFigure._position.z))
                throw std::runtime_error("Missing 'z' value for sphere.");
            if (!p.lookupValue("r", newFigure.size))
                throw std::runtime_error("Missing 'r' value for sphere.");

            // Sphere Color
            const libconfig::Setting &colorFile = part[i]["color"];

            if (!colorFile.lookupValue("r", newFigure._color.r))
                throw std::runtime_error("Missing 'r' value for sphere color.");
            if (!colorFile.lookupValue("g", newFigure._color.g))
                throw std::runtime_error("Missing 'g' value for sphere color.");
            if (!colorFile.lookupValue("b", newFigure._color.b))
                throw std::runtime_error("Missing 'b' value for sphere color.");
    
            prim->_listFigure.push_back(newFigure);
        }
    } catch (libconfig::SettingNotFoundException &e) {
        throw (std::runtime_error(e.what()));
    }
}

void Raytracer::Parser::parsePlane(const libconfig::Setting &part, struct Raytracer::Primitives *prim)
{
    Raytracer::Planes newPlanes;

    try {
        for (int i = 0; i < part.getLength(); ++i) {
            const libconfig::Setting &p = part[i];
            if (!p.lookupValue("axis", newPlanes._axis))
                throw std::runtime_error("Missing 'axis' value for plane.");
            if (!p.lookupValue("position", newPlanes._position))
                throw std::runtime_error("Missing 'position' value for plane.");

            const libconfig::Setting &colorFile = part[i]["color"];
            if (!colorFile.lookupValue("r", newPlanes._color.r))
                throw std::runtime_error("Missing 'r' value for plane color.");
            if (!colorFile.lookupValue("g", newPlanes._color.g))
                throw std::runtime_error("Missing 'g' value for plane color.");
            if (!colorFile.lookupValue("b", newPlanes._color.b))
                throw std::runtime_error("Missing 'b' value for plane color.");
        }
    } catch (libconfig::SettingNotFoundException &e) {
        throw (std::runtime_error(e.what()));
    }
    prim->_listPlane.push_back(newPlanes);
}

void Raytracer::Parser::parseInfoPrimitives()
{
    struct Raytracer::Primitives primitives;

    try {
        for (size_t count = 0; count < (sizeof(primitivesFunctions) / sizeof(primitivesFunctions[0])); ++count) {
            const libconfig::Setting &root = _config.getRoot();
            const libconfig::Setting &primitivesPart = root["primitives"];
            std::string path = "primitives." + primitivesFunctions[count].name;

            if (_config.exists(path)) {
                try {
                    const libconfig::Setting &figure = primitivesPart[primitivesFunctions[count].name];
                    (this->*primitivesFunctions[count].function)(figure, &primitives);
                } catch (std::runtime_error &e) {
                    throw std::runtime_error(e.what());
                }
            }
        }
    } catch (std::runtime_error &e) {
        throw (std::runtime_error(e.what()));
    } catch (libconfig::SettingNotFoundException &e) {
        throw (std::runtime_error(e.what()));
    }
    setPrimitive(primitives);
}
