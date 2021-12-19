#include <fstream>
#include <iostream>
#include <limits>

#include "AoC-Utils/algorithm/sliding_window.hpp"

namespace AoC::Day1 {

    void star_one()
    {
        std::fstream input{ "input.txt"};
        int count = 0;
        AoC::sliding_window<2>(std::istream_iterator<int>{input}, std::istream_iterator<int>{}, [&](int i, int j) { if (i < j) ++count; });
        std::cout << count;
    }

    void star_two()
    {
        std::fstream input("input.txt");
        int count = 0;
        int prevSum = std::numeric_limits<int>::max();
        AoC::sliding_window<3>(std::istream_iterator<int>{input}, std::istream_iterator<int>{},
            [&](int i, int j, int k) {
                int const sum = i + j + k;
                if (sum > prevSum) {
                    prevSum = sum;
                    ++count;
                }
            }
        );
        std::cout << count;
    }

}


int main() {
    AoC::Day1::star_one();
    AoC::Day1::star_two();
}
