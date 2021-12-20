#include <fstream>
#include <iostream>
#include <limits>

#include "AoC-Utils/algorithm/sliding_window.hpp"

namespace AoC::Day1 {

    int star_one()
    {
        std::fstream input{ "input.txt"};
        int count = 0;
        AoC::sliding_window<2>(std::istream_iterator<int>{input}, std::istream_iterator<int>{}, [&](int i, int j) { if (i < j) ++count; });
        return count;
    }

    int star_two()
    {
        std::fstream input("input.txt");
        int count = -1;
        int prevSum = 0;
        AoC::sliding_window<3>(std::istream_iterator<int>{input}, std::istream_iterator<int>{},
            [&](int i, int j, int k) {
                int const sum = i + j + k;
                if (sum > prevSum) {
                    ++count;
                }
                prevSum = sum;
            }
        );
        return count;
    }

}


int main() {
    std::cout << AoC::Day1::star_one() << '\n';
    std::cout << AoC::Day1::star_two() << '\n';
}
