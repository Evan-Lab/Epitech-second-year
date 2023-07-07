/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** circuit
*/

#include "model/circuit.hpp"
#include "model/component/and.hpp"
#include "cross_cutting/exception.hpp"

#include "model/component/input.hpp"
#include "model/component/output.hpp"
#include "model/component/not.hpp"
#include "model/component/or.hpp"
#include "model/component/input_output.hpp"
#include "model/component/true.hpp"
#include "model/component/xor.hpp"
#include "model/component/false.hpp"
#include "model/component/clock.hpp"
#include "model/component/4081_and.hpp"
#include "model/component/4071_or.hpp"
#include "model/component/4011_nand.hpp"
#include "model/component/4001_nor.hpp"
#include "model/component/4030_xor.hpp"
#include "model/component/4069_not.hpp"
#include "model/component/and_or_not.hpp"

namespace nts {

    void Circuit::add_chipset(const std::string &type, const std::string &name)
    {
        if (_chipsets.contains(name)) {
            throw Exception("Component already exists: " + name);
        }
        if (type == "input") {
            _inputs[name] = Undefined;
            _chipsets[name] = std::make_unique <Input>(_inputs[name]);
        } else if (type == "output") {
            _outputs[name] = Undefined;
            _chipsets[name] = std::make_unique <Output>();
        } else if (type == "clock") {
            _inputs[name] = Undefined;
            _chipsets[name] = std::make_unique <Clock>(_inputs[name]);
        } else if (type == "and") {
            _chipsets[name] = std::make_unique <And>();
        } else if (type == "not") {
            _chipsets[name] = std::make_unique <Not>();
        } else if (type == "or") {
            _chipsets[name] = std::make_unique <Or>();
        } else if (type == "input_output") {
            _chipsets[name] = std::make_unique <Input_Output>();
        } else if (type == "xor") {
            _chipsets[name] = std::make_unique <Xor>();
        } else if (type == "4081") {
            _chipsets[name] = std::make_unique <And_4081>();
        } else if (type == "4071") {
            _chipsets[name] = std::make_unique <Or_4071>();
        } else if (type == "4011") {
            _chipsets[name] = std::make_unique <Nand_4011>();
        } else if (type == "4001") {
            _chipsets[name] = std::make_unique <Nor_4001>();
        } else if (type == "4030") {
            _chipsets[name] = std::make_unique <Xor_4030>();
        } else if (type == "4069") {
            _chipsets[name] = std::make_unique <Not_4069>();
        } else if (type == "false") {
            _chipsets[name] = std::make_unique <My_False>();
        } else if (type == "true") {
            _chipsets[name] = std::make_unique <My_True>();
        } else if (type == "and_or_not") {
            _chipsets[name] = std::make_unique <And_or_not>();
        } else {
            throw Exception("Unknown component type: " + type);
        }
    }
}
