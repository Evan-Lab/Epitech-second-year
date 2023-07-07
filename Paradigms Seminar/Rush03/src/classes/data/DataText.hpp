/*
** EPITECH PROJECT, 2023
** POOL
** File description:
** DataText
*/

#include <string>
#include <vector>
#include <algorithm>

class Data {
    public:
        Data(std::string name, std::string filename) : _name(name), _unit("N/A"), _nbValues(0), _values({}), _fileName(filename) {};
        ~Data() {};

        const std::string getName() const { return this->_name; };
        const std::string getUnit() const { return this->_unit; };
        const std::vector <unsigned int> getValues() const { return this->_values; };
        unsigned int getMaxValue() const { return *max_element(this->_values.begin(),this->_values.end());; };

        void updateValues();

        void pushValues(unsigned int value);

    private:
        std::string _name;
        std::string _unit;
        std::vector <unsigned int> _values;
        int _nbValues;
        std::string _fileName;
};