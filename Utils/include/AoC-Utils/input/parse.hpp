#pragma once
#include <string_view>
#include <charconv>
#include <cassert>

namespace AoC {

	int parse_int(std::string_view src, int base = 10) {
		int res{};
		auto [_, ec] = std::from_chars(src.data(), src.data() + src.size(), res, base);
		assert(ec == std::errc());
		return res;
	}

}
