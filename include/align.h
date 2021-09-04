#ifndef ALIGN_H
#define ALIGN_H

#include <string>
#include <iostream>
#include <algorithm>
#include <tuple>

std::tuple<std::string, std::string> align(const std::string_view& left, const std::string_view& right) {

    const int llen = left.length();
    const int rlen = right.length();
    int grid [llen + 1][rlen + 1];

    const auto indel = -2;
    const auto match = 3;

    for (auto i = 0; i < llen + 1; ++i) {
        for (auto j = 0; j < rlen + 1; ++j) {
            if (i == 0) {
                grid[i][j] = j * indel;
            } else if (j == 0) {
                grid[i][j] = i * indel;
            } else {
                auto t = grid[i][j - 1] + indel;
                auto l = grid[i - 1][j] + indel;
                auto tl = left[i - 1] == right[j - 1] ? match : -match;
                tl += grid[i - 1][j - 1];
                grid[i][j] = std::max(std::max(t, l), tl);
            }
            if (grid[i][j] >= 0) {
                std::cout << " ";
            }
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::string leftOut;
    std::string rightOut;

    auto i = llen;
    auto j = rlen;

    leftOut += left[i];
    rightOut += right[j];

    while(i >= 1 && j >= 1) {

        auto di = 0;
        auto dj = -1;
        auto m = grid[i + di][j + dj];

        if (grid[i - 1][j - 1] > m) {
            di = -1;
            dj = -1;
            m = grid[i + di][j + dj];
        }
        if (grid[i - 1][j] > m) {
            di = -1;
            dj = 0;
            m = grid[i + di][j + dj];
        }

        i += di;
        j += dj;

        if (di == -1 && dj == -1) {
            leftOut += left[i];
            rightOut += right[j];
        } else if (di == -1 && dj == 0) {
            rightOut += "-";
            leftOut += left[i];
        } else {
            leftOut += "-";
            rightOut += right[j];
        }
    }

    std::reverse(leftOut.begin(), leftOut.end());
    std::reverse(rightOut.begin(), rightOut.end());

    return std::make_tuple(leftOut, rightOut);
}

#endif // ALIGN_H
