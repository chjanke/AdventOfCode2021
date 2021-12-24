#include <boost/ut.hpp>

#include "day3.hpp"

int main()
{
	using namespace boost::ut;

	std::string const example =
		R"(00100
11110
10110
10111
10101
01111
00111
11100
10000
11001
00010
01010)";

	"Day3::star_one"_test = [&] {
		std::istringstream in{ example };
		expect(AoC::Day3::star_one(in) == 198_i);
	};
	"Day2::star_two"_test = [&] {
		std::istringstream in{ example };
		expect(AoC::Day3::star_two(in) == 230_i);
	};
}