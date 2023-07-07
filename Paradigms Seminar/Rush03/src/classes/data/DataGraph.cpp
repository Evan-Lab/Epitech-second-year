/*
** EPITECH PROJECT, 2023
** POOL
** File description:
** DataGraph
*/

#include "DataGraph.hpp"

void DataGraph::updateValues()
{
    std::ifstream file(this->_fileName);
    std::string line;
    while (std::getline(file, line)) {
        if (line.find(this->_valueName) != std::string::npos) {
            std::string value = line.substr(line.find(":") + 1);
            this->pushValues(std::stod(value));
            break;
        }
    }
}

void DataGraph::pushValues(double value)
{
    this->_values.push_back(value);
    if (this->_values.size() >= this->_nbValues)
        this->_values.erase(this->_values.begin());
}