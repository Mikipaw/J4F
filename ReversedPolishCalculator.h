//
// Created by mikhalinho on 08.10.2021.
//

#ifndef J4F_REVERSEDPOLISHCALCULATOR_H
#define J4F_REVERSEDPOLISHCALCULATOR_H

#include <iostream>
#include <cstdlib>
#include <sstream>

//Checking if str is an operator like '+', '-', '*' or '/'
bool is_oper(const std::string& str);

class calculator {
public:
    calculator() = default;

    //Takes input string to calculate from user
    int GetEquation();

    //Calculating
    int Work();

private:
    int Calculate(char op, std::string& first, std::string& second);

    std::stringstream ss;
};

#endif //J4F_REVERSEDPOLISHCALCULATOR_H
