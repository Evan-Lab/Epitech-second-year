/*
** EPITECH PROJECT, 2023
** day13
** File description:
** Stack
*/

#pragma once

#include <stack>
#include <exception>
#include <string>

class Stack {
    private:
        std::stack<double> data;
    public:
        class Error : public std::exception {
            private:
                std::string message;
            public:
                Error(const std::string& msg) : message(msg) {}
                const char* what() const noexcept { return message.c_str(); }
        };
        void push(double value);
        double pop();
        double top() const;
        void add();
        void sub();
        void mul();
        void div();
};