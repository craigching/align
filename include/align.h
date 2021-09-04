#ifndef ALIGN_H
#define ALIGN_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>

template<typename T, int GAP_COST = -2, int MATCH_COST = 3>
std::tuple<std::vector<T>, std::vector<T>>
align(const std::vector<T>& left, const std::vector<T>& right, const T& GAP) {

    const int llen = left.size();
    const int rlen = right.size();
    int grid [llen + 1][rlen + 1];

    for (auto i = 0; i < llen + 1; ++i) {
        for (auto j = 0; j < rlen + 1; ++j) {
            if (i == 0) {
                grid[i][j] = j * GAP_COST;
            } else if (j == 0) {
                grid[i][j] = i * GAP_COST;
            } else {
                auto t = grid[i][j - 1] + GAP_COST;
                auto l = grid[i - 1][j] + GAP_COST;
                auto tl = left[i - 1] == right[j - 1] ? MATCH_COST : -MATCH_COST;
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

    std::vector<T> leftOut;
    std::vector<T> rightOut;

    auto i = llen;
    auto j = rlen;

    leftOut.push_back(left[i]);
    rightOut.push_back(right[j]);

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
            leftOut.push_back(left[i]);
            rightOut.push_back(right[j]);
        } else if (di == -1 && dj == 0) {
            rightOut.push_back(GAP);
            leftOut.push_back(left[i]);
        } else {
            leftOut.push_back(GAP);
            rightOut.push_back(right[j]);
        }
    }

    std::reverse(leftOut.begin(), leftOut.end());
    std::reverse(rightOut.begin(), rightOut.end());

    return std::make_tuple(leftOut, rightOut);
}

std::tuple<std::string, std::string> align(const std::string_view& left, const std::string_view& right) {
    auto [leftOut, rightOut] = align<char>(std::vector<char>{left.begin(), left.end()}, std::vector<char>{right.begin(), right.end()}, '-');
    return std::make_tuple(std::string{leftOut.begin(), leftOut.end()}, std::string{rightOut.begin(), rightOut.end()});
}

#endif // ALIGN_H
