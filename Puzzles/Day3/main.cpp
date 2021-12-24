#include <iostream>

#include <AoC-Utils/input/input.hpp>

#include "day3.hpp"



int main() {
    std::fstream input = AoC::read_input();
    std::cout << AoC::Day3::star_one(input) << '\n';
    input.clear();
    input.seekg(0);
    std::cout << AoC::Day3::star_two(input) << '\n';
}
