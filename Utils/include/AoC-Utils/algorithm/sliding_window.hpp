#include <cstdint>
#include <array>
#include <functional>
#include <algorithm>
#include <type_traits>
#include <iterator>

namespace AoC {

    template <size_t Size, typename It, typename F>
    constexpr void sliding_window(It begin, It end, F fn)
    {
        std::array<std::iter_value_t<It>, Size> cache;
        It cur = begin;
        for (std::size_t i = 0; i < Size - 1; ++i) {
            cache[i] = *cur;
            ++cur;
        }
        while (cur != end) {
            cache[Size - 1] = *cur;
            std::apply(fn, cache);
            std::shift_left(cache.begin(), cache.end(), 1);
            ++cur;
        }
    }

}
