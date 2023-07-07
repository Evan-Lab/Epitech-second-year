/*
** EPITECH PROJECT, 2022
** RUSH3
** File description:
** DataGraph.hpp
*/

#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <ctime>
#include <limits.h>
#include <sys/utsname.h>
#include <unistd.h>

class DataGraph {
    public:
        DataGraph(std::string name, std::string filename, std::string valueName, std::string Unit) : _name(name), _unit(Unit), _nbValues(18), _values({}), _fileName(filename), _valueName(valueName) {};
        DataGraph() {};
        ~DataGraph() {};
        const std::string getName() const { return this->_name; };
        const std::string getUnit() const { return this->_unit; };
        const std::vector <double> getValues() const { return this->_values; };
        const double getMaxValue() const { return *max_element(this->_values.begin(),this->_values.end());; };
        void updateValues();
        void pushValues(double value);
        std::vector<DataGraph> init() const;
        const void info_user_host(std::string &_hostname, std::string &_logname);
        const void time();
    private:
        std::string _name;
        std::string _unit;
        std::vector <double> _values;
        int _nbValues;
        std::string _fileName;
        std::string _valueName;
        std::string _hostname;
        std::string _logname;
        std::string _operatesystem;
        std::string _kernelversion;
        std::string _date;
        std::string _time;
};