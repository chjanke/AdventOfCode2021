#include <istream>
#include <fstream>
#include <string>
#include <vector>

namespace AoC {

	inline std::fstream read_input()
	{
		return std::fstream{ "input.txt" };
	}

	template<typename T>
	std::vector<T> read_input_values()
	{
		auto file = read_input();
		return { std::istream_iterator<T>{file}, std::istream_iterator<T>{} };
	}

	inline std::string read_input_string()
	{
		auto file = read_input();
		return { std::istream_iterator<char>{file}, std::istream_iterator<char>{} };
	}


}
