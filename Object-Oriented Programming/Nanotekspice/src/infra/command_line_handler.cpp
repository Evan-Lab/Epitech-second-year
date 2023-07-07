/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** command_line_handler
*/

#include "infra/command_line_handler.hpp"

#include "cross_cutting/exception.hpp"

#include <filesystem>

namespace {

    void check_and_throw_if_not_exists(const std::filesystem::path &filepath)
    {
        if (!std::filesystem::exists(filepath)) {
            throw nts::Exception("No such file or directory: " + filepath.string());
        }
    }

    void check_and_throw_if_empty(const std::filesystem::path &filepath)
    {
        if (std::filesystem::is_empty(filepath)) {
            throw nts::Exception("File is empty: " + filepath.string());
        }
    }
    void check_and_throw_if_not_open(std::ifstream &stream)
    {
        if (!stream.is_open()) {
            throw nts::Exception("Could not open the file stream");
        }
    }
    void check_and_throw_if_file_is_nts(const std::filesystem::path &filepath)
    {
        if (filepath.extension() != ".nts") {
            throw nts::Exception("File does not have .nts extension: " + filepath.string());
        }
    }
}

namespace nts {

    std::ifstream Command_line_handler::process_argument(int argc, char **argv)
    {
        if (argc != 2) {
            throw Exception("Usage: ./nanotekspice file.nts");
        }
        std::filesystem::path filepath(argv[1]);
        check_and_throw_if_not_exists(filepath);
        check_and_throw_if_file_is_nts(filepath);
        check_and_throw_if_empty(filepath);
        std::ifstream stream(filepath.string());
        check_and_throw_if_not_open(stream);
        return stream;
    }

}