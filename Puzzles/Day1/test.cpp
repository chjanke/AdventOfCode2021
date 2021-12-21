#include <boost/ut.hpp>

#include "day1.hpp"

int main()
{
	using namespace boost::ut;
	std::string example =R"(199
200
208
210
200
207
240
269
260
263)";

	"Day1::star_one"_test = [&] {
		std::istringstream in{ example };
		expect(AoC::Day1::star_one(in) == 7_i);
	};
	"Day1::star_two"_test = [&] {
		std::istringstream in{ example };
		expect(AoC::Day1::star_two(in) == 5_i);
	};
}