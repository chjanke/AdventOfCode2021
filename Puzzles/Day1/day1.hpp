#include "AoC-Utils/algorithm/sliding_window.hpp"

#include <iostream>
#include <iterator>

namespace AoC::Day1 {

    inline int star_one(std::istream& input)
    {
        int count = 0;
        AoC::sliding_window<2>(std::istream_iterator<int>{input}, std::istream_iterator<int>{}, [&](int i, int j) { if (i < j) ++count; });
        return count;
    }

    inline int star_two(std::istream& input)
    {
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
