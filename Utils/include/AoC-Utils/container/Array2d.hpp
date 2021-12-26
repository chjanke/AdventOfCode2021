#pragma once

#include <array>
#include <cstddef>
#include <cassert>


namespace AoC {
	//TODO: Add Column and Row Iterators
	template<typename T, std::size_t Rows, std::size_t Columns>
	struct Array2D {
		static constexpr std::size_t NumElements = Rows * Columns;
		static constexpr std::size_t Rows = Rows;
		static constexpr std::size_t Columns = Columns;

		std::array<T, NumElements> data;

		constexpr T& operator()(std::size_t row, std::size_t column) noexcept {
			return data[index(row, column)];
		}

		constexpr T const& operator()(std::size_t row, std::size_t column) const noexcept {
			return data[index(row, column)];
		}

	private:
		constexpr std::size_t index(std::size_t row, std::size_t column) const noexcept {
			return row * Columns + column;
		}
	};

}
