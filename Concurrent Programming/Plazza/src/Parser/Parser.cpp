/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** Parser
*/

#include "Parser.hpp"

namespace Plazza {

    // Parser

        // Public Function
    Parser::Parser(std::string strToParse)
    {
        try {
            splitCommand(strToParse);
            createCommand();
        } catch (ParserError &e) {
            throw std::runtime_error(e.what());
        }
    }

    Parser::~Parser()
    {
    }

    std::vector<Command> Parser::getCommand() const
    {
        return _command;
    }

        // Private Function

    void Parser::splitCommand(std::string str)
    {
        std::stringstream ss(str);
        std::string buffer;
        std::vector<std::string> command;
        size_t count = 0;

        if (str[str.size() - 1] == ';')
            throw ParserError("[ParseError] Invalid end of command, the end of the order must not end with ';'");
        while (std::getline(ss, buffer, ';'))
            command.push_back(buffer);

        while (count < command.size()) {
            if (command[count][0] == ' ')
                command[count] = command[count].substr(1);

            std::stringstream stream(command[count]);
            std::vector<std::string> stock;

            while (std::getline(stream, buffer, ' '))
                stock.push_back(buffer);

            if (stock.size() != 3)
                throw ParserError("[ParseError] Order no respect the following grammar: TYPE SIZE NUMBER");
            _strParse.push_back(stock);
            ++count;
        }
    }

    PizzaType Parser::getPizzaType(std::string type) const
    {
        if (type == "regina")
            return PizzaType::Regina;
        if (type == "margarita")
            return PizzaType::Margarita;
        if (type == "americana")
            return PizzaType::Americana;
        if (type == "fantasia")
            return PizzaType::Fantasia;
        throw ParserError("[ParseError] Invalid type of pizza");
    }

    PizzaSize Parser::getPizzaSize(std::string size) const
    {
        if (size == "S")
            return PizzaSize::S;
        if (size == "M")
            return PizzaSize::M;
        if (size == "L")
            return PizzaSize::L;
        if (size == "XL")
            return PizzaSize::XL;
        if (size == "XXL")
            return PizzaSize::XXL;
        throw ParserError("[ParseError] Invalid size of pizza");
    }

    int Parser::getPizzaNumber(std::string number) const
    {
        int value = 0;

        if (number.size() < 2)
            throw ParserError("[ParserError] Invalid Value");
        if (number[0] != 'x')
            throw ParserError("[ParseError] Number of pizza must be start with 'x'");
        number = number.substr(1);
        try {
            value = std::stoi(number);
        } catch (std::exception &e) {
            throw ParserError(e.what());
        }
        return value;
    }

    void Parser::createCommand()
    {
        size_t count = 0;
        Command newCommand;

        while (count < _strParse.size()) {
            newCommand.pizza = getPizzaType(_strParse[count][0]);
            newCommand.size = getPizzaSize(_strParse[count][1]);
            newCommand.number = getPizzaNumber(_strParse[count][2]);
            _command.push_back(newCommand);
            ++count;
        }
    }

    // ParserError

    Parser::ParserError::ParserError(std::string msg)
    {
        _msg = msg;
    }

    Parser::ParserError::~ParserError()
    {
    }

    const char *Parser::ParserError::what() const noexcept
    {
        return _msg.c_str();
    }
}
