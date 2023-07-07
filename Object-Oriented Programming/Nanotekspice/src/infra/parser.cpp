/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** parser
*/

#include "infra/parser.hpp"

#include "cross_cutting/exception.hpp"
#include "cross_cutting/string_utils.hpp"

#include <map>
#include <string>

namespace {
    enum State {
        START,
        CHIPSETS,
        LINKS
    };
    const std::string CHIPSET_MARKER = ".chipsets";
    const std::string LINKS_MARKER = ".links";

    void check_and_throw_if_no_chipsets(const nts::Circuit &circuit)
    {
        if (circuit._chipsets.empty()) {
            throw nts::Exception("Invalid file format: missing chipsets");
        }
    }
    void check_and_throw_if_different_status(State actual_state, State expected_state)
    {
        if (actual_state != expected_state) {
            throw nts::Exception("Invalid file format: ");
        }
    }
    std::string trim_line(const std::string &line)
    {
        std::string trimmed_line = line;
        trimmed_line = trimmed_line.substr(0, trimmed_line.find('#'));
        trimmed_line.erase(0, trimmed_line.find_first_not_of(' '));
        trimmed_line.erase(trimmed_line.find_last_not_of(' ') + 1);
        return trimmed_line;
    }

    void add_chipset(nts::Circuit &circuit, const std::string &line)
    {
        const auto [type, name] = nts::String_utils::split(line, ' ');
        circuit.add_chipset(type, name);
    }

    void add_link(const std::map <std::string, std::unique_ptr <nts::IComponent>> &chipsets, const std::string &line)
    {
        const auto [src, dst] = nts::String_utils::split(line, ' ');
        const auto [src_name, src_pin_name] = nts::String_utils::split(src, ':');
        const auto [dst_name, dst_pin_name] = nts::String_utils::split(dst, ':');

        nts::IComponent &src_chipset = *chipsets.at(src_name);
        nts::IComponent &dst_chipset = *chipsets.at(dst_name);
        const size_t src_pin = std::stoi(src_pin_name);
        const size_t dst_pin = std::stoi(dst_pin_name);
        src_chipset.setLink(src_pin, dst_chipset, dst_pin);
        dst_chipset.setLink(dst_pin, src_chipset, src_pin);
    }

}

namespace nts {

    Circuit Parser::parse(std::istream &stream)
    {
        State status = START;
        Circuit circuit;
        std::string line;
        while (getline(stream, line)) {
            line = trim_line(line);
            if (line.empty() || line[0] == '#') {
                continue;
            } else if (line.starts_with(CHIPSET_MARKER)) {
                check_and_throw_if_different_status(status, START);
                status = CHIPSETS;
            } else if (line.starts_with(LINKS_MARKER)) {
                check_and_throw_if_different_status(status, CHIPSETS);
                status = LINKS;
            } else if (status == CHIPSETS) {
                add_chipset(circuit, line);
            } else if (status == LINKS) {
                add_link(circuit._chipsets, line);
            } else {
                throw Exception("Invalid file format: " + line);
            }
        }
        check_and_throw_if_no_chipsets(circuit);
        return circuit;
    }

}
