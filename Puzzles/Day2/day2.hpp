#include <string_view>

namespace AoC::Day2 {

	constexpr std::string_view kForward = "forward";
	constexpr std::string_view kDown = "down";
	constexpr std::string_view kUp = "up";

	int star_one(std::istream& input)
	{
		int sub_pos = 0;
		int depth = 0;
		std::string line;
		while (std::getline(input, line)) {
			auto split_pos = line.find(' ');
			std::string_view cmd{ line.c_str(), split_pos };
			int val = std::atoi(line.c_str() + split_pos);
			if (cmd == kForward) {
				sub_pos += val;
			}
			else if (cmd == kDown) {
				depth += val;
			}
			else {
				depth -= val;
			}
		}
		return sub_pos * depth;
	}

	int star_two(std::istream& input)
	{
		int sub_pos = 0;
		int aim = 0;
		int depth = 0;
		std::string line;
		while (std::getline(input, line)) {
			auto split_pos = line.find(' ');
			std::string_view cmd{ line.c_str(), split_pos };
			int val = std::atoi(line.c_str() + split_pos);
			if (cmd == kForward) {
				sub_pos += val;
				depth += aim * val;
			}
			else if (cmd == kDown) {
				aim += val;
			}
			else {
				aim -= val;
			}
		}
		return sub_pos * depth;
	}

}
