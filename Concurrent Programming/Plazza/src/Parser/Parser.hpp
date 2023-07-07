/*
** EPITECH PROJECT, 2023
** B-CCP-400-PAR-4-1-theplazza-evan.labourdette
** File description:
** Parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

    #include <exception>
    #include <string>
    #include <cstring>
    #include <vector>
    #include <sstream>
    #include <iostream>
    #include "../../include/enum.hpp"

namespace Plazza {

    struct Command {
        PizzaType pizza;
        PizzaSize size;
        int number;
    };

    class Parser {
    public:
        Parser(std::string strToParse);
        ~Parser();

        std::vector<Command> getCommand() const;

        class ParserError : public std::exception {
        public:
            ParserError(std::string msg);
            ~ParserError();

            const char *what() const noexcept override;

        private:
            std::string _msg;
        };

    private:
        void splitCommand(std::string str);
        void createCommand();
        PizzaType getPizzaType(std::string type) const;
        PizzaSize getPizzaSize(std::string size) const;
        int getPizzaNumber(std::string number) const;

        std::vector<std::vector<std::string>> _strParse;
        std::vector<Command> _command;
    };

}

#endif /* !PARSER_HPP_ */
