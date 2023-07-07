/*
** EPITECH PROJECT, 2023
** day13
** File description:
** Stack
*/

#include "Stack.hpp"

void Stack::push(double value) {
    data.push(value);
}

double Stack::pop() {
    if (data.empty()) {
        throw Error("Empty stack");
    }
    double value = data.top();
    data.pop();
    return value;
}

double Stack::top() const {
    if (data.empty()) {
        throw Error("Empty stack");
    }
    return data.top();
}

void Stack::add() {
    if (data.size() < 2) {
        throw Error("Not enough operands");
    }
    double value1 = pop();
    double value2 = pop();
    double value3 = value1 + value2;
    push(value3);
}

void Stack::sub() {
    if (data.size() < 2) {
        throw Error("Not enough operands");
    }
    double value1 = pop();
    double value2 = pop();
    double value3 = value1 - value2;
    push(value3);
}

void Stack::mul() {
    if (data.size() < 2) {
        throw Error("Not enough operands");
    }
    double value1 = pop();
    double value2 = pop();
    double value3 = value1 * value2;
    push(value3);
}

void Stack::div() {
    if (data.size() < 2) {
        throw Error("Not enough operands");
    }
    double value1 = pop();
    double value2 = pop();
    double value3 = value1 / value2;
    push(value3);
}