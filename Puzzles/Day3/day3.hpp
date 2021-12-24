#include <string_view>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

namespace AoC::Day3 {

	inline int binary_to_decimal(std::string const& binary)
	{
		int decimal = 0;
		for (int i = 0; i < binary.size(); ++i) {
			if (binary[binary.size() - 1 - i] == '1') {
				decimal += (1 << i);
			}
		}
		return decimal;
	}

	inline void append_transposed(std::string const& binary, std::vector<std::string>& input_transposed)
	{
		for (int i = 0; i < binary.size(); ++i) {
			input_transposed[i].push_back(binary[i]);
		}
	}


	inline int star_one(std::istream& input)
	{
		std::vector<std::string> input_transposed;
		std::string line;
		std::getline(input, line);
		input_transposed.resize(line.size());
		append_transposed(line, input_transposed);
		while (std::getline(input, line)) {
			append_transposed(line, input_transposed);
		}
		std::string gamma_binary, epsilon_binary;
		for (auto const& bits : input_transposed) {
			auto const one_count = std::count(bits.cbegin(), bits.cend(), '1');
			auto const zero_count = bits.size() - one_count;
			if (one_count > zero_count) {
				gamma_binary.push_back('1');
				epsilon_binary.push_back('0');
			}
			else {
				gamma_binary.push_back('0');
				epsilon_binary.push_back('1');
			}
		}
		int const gamma_rate = binary_to_decimal(gamma_binary);
		int const epsilon_rate = binary_to_decimal(epsilon_binary);
		return gamma_rate * epsilon_rate;
	}

	inline int star_two(std::istream& input)
	{
		//TODO: this is an algo
		std::vector<std::string> report_lines;
		std::string line;
		while (std::getline(input, line)) {
			report_lines.push_back(line);
		}
		auto const num_lines = report_lines.size();
		auto const num_bits = report_lines.front().size();
		std::vector<size_t> oxy_rating_candidates(report_lines.size());
		std::iota(oxy_rating_candidates.begin(), oxy_rating_candidates.end(), 0);
		std::vector<size_t> co2_rating_candidates = oxy_rating_candidates;
		for (int i = 0; i < num_bits; ++i) {
			auto const oxy_one_count = std::count_if(oxy_rating_candidates.cbegin(), oxy_rating_candidates.cend(), [&](std::size_t idx) { return report_lines[idx][i] == '1'; });
			auto const oxy_zero_count = oxy_rating_candidates.size() - oxy_one_count;
			char const oxy_filter_bit = oxy_one_count >= oxy_zero_count ? '1' : '0';
			auto const co2_one_count = std::count_if(co2_rating_candidates.cbegin(), co2_rating_candidates.cend(), [&](std::size_t idx) { return report_lines[idx][i] == '1'; });
			auto const co2_zero_count = co2_rating_candidates.size() - co2_one_count;
			char const co2_filter_bit = co2_zero_count <= co2_one_count ? '0' : '1';
			auto oxy_filter_pred = [&](size_t idx) { return report_lines[idx][i] != oxy_filter_bit; };
			auto co2_filter_pred = [&](size_t idx) { return report_lines[idx][i] != co2_filter_bit; };
			if (oxy_rating_candidates.size() > 1) {
				oxy_rating_candidates.erase(std::remove_if(oxy_rating_candidates.begin(), oxy_rating_candidates.end(), oxy_filter_pred), oxy_rating_candidates.end());
			}
			if (co2_rating_candidates.size() > 1) {
				co2_rating_candidates.erase(std::remove_if(co2_rating_candidates.begin(), co2_rating_candidates.end(), co2_filter_pred), co2_rating_candidates.end());
			}
		}
		int const oxy_rating = binary_to_decimal(report_lines[oxy_rating_candidates.front()]);
		int const co2_rating = binary_to_decimal(report_lines[co2_rating_candidates.front()]);
		return oxy_rating * co2_rating;
	}

}
