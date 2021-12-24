#include <boost/ut.hpp>

#include "day2.hpp"

int main()
{
	using namespace boost::ut;

	std::string const example =
		R"(forward 5
down 5
forward 8
up 3
down 8
forward 2)";

	"Day2::star_one"_test = [&] {
		std::istringstream in{ example };
		expect(AoC::Day2::star_one(in) == 150_i);
	};
	"Day2::star_two"_test = [&] {
		std::istringstream in{ example };
		expect(AoC::Day2::star_two(in) == 900_i);
	};
}