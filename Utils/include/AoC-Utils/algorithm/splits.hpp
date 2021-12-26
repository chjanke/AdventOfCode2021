#pragma once
#include <string_view>

namespace AoC {

	template<typename Fn>
	void string_splits(std::string_view src, Fn fn, char delim = ' ') {
		auto splitBegin = 0;
		auto splitEnd = src.find(delim, 0);
		fn(src.substr(splitBegin, splitEnd - splitBegin));
		while (splitEnd != std::string_view::npos) {
			splitBegin = splitEnd + 1;
			splitEnd = src.find(delim, splitBegin);
			std::string_view split = src.substr(splitBegin, splitEnd - splitBegin);
			fn(split);
		}
	}

}
