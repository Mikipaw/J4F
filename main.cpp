//
// Created by mikhalinho on 20.09.2021.
//

#include <cstdio>

#include "matrix.h"
#include "ReversedPolishCalculator.h"

int main() {
    printf("You are welcome!\n");
    int N = 0;

    calculator calc;
    calc.GetEquation();
    int result = calc.Work();

    std::cout << result << '\n';

    return 0;
}
