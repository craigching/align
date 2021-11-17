#include <iostream>

#include "align.h"

int main(int argc, char* argv[]) {

    // std::string left{"GCATGCU"};
    // std::string right{"GATTACA"};

    // std::string left{"GAAC"};
    // std::string right{"CAAGAC"};

    // std::string left{"AATCG"};
    // std::string right{"AACG"};

    // std::string left{"GGTTGACTA"};
    // std::string right{"TGTTACGG"};

    std::string left{"HEAGAWGHEE"};
    std::string right{"PAWHEAE"};

    std::cout << "aligning " << left << " and " << right << std::endl;

    auto [leftOut, rightOut] = align2(left, right);
    // auto [leftOut, rightOut] = align(left, right);
    std::cout << "l: " << leftOut << "\nr: " << rightOut << std::endl;

    return 0;
}