#include <iostream>

#include "align.h"

int main(int argc, char* argv[]) {

    // std::string left{"GCATGCU"};
    // std::string right{"GATTACA"};
    std::string left{"GAAC"};
    std::string right{"CAAGAC"};

    std::cout << "aligning " << left << " and " << right << std::endl;

    auto [leftOut, rightOut] = align(left, right);
    std::cout << "leftOut: " << leftOut << "\nrightOut: " << rightOut << std::endl;

    return 0;
}