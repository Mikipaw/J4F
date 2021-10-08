//
// Created by mikhalinho on 08.10.2021.
//
#include "ReversedPolishCalculator.h"


bool is_oper(const std::string& str) {
    char c = str[0];
    return (c == '*' || c == '+' || c == '-' || c == '/') && str.size() < 2;
}

int calculator::GetEquation() {
    std::string str;
    std::getline(std::cin,str);
    ss << str;

    return 0;
}

int calculator::Work() {
    char a = 0;

    std::string b, c;
    ss >> a >> b >> c;

    return Calculate(a, b, c);
}

int calculator::Calculate(char op, std::string& first, std::string& second) {

    while (is_oper(second) || is_oper(first)) {
        if (is_oper(second)) {
            std::string c, d;
            ss >> c >> d;
            second = std::to_string(Calculate(second[0], c, d));
        }

        if (is_oper(first)) {
            std::string e, f;
            ss >> e;
            first = std::to_string(Calculate(first[0], second, e));
            ss >> f;
            second = f;
        }
    }

    switch (op) {
        case '+':
            return atoi(first.data()) + atoi(second.data());

        case '-':
            return atoi(first.data()) - atoi(second.data());

        case '*':
            return atoi(first.data()) * atoi(second.data());

        case '/':
            return atoi(first.data()) / atoi(second.data());

        default:
            break;
    }

    return 0;
}



