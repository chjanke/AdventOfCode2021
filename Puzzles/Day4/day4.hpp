#include <iostream>
#include <vector>
#include <utility>
#include <optional>

#include <AoC-Utils/container/Array2D.hpp>
#include <AoC-Utils/algorithm/splits.hpp>
#include <AoC-Utils/input/parse.hpp>


namespace AoC::Day4 {

	using BingoBoard = AoC::Array2D<int, 5, 5>;
	using BingoBoardMarks = AoC::Array2D<bool, 5, 5>;

	class BingoGame {
		std::vector<BingoBoard> m_boards;
		std::vector<BingoBoardMarks> m_marks;
	public:
		BingoGame(std::vector<BingoBoard> boards) : m_boards(std::move(boards)) {
			m_marks.resize(m_boards.size());
		}

		BingoBoard const& get_board(std::size_t idx) const noexcept { return m_boards[idx]; }
		BingoBoardMarks const& get_marks(std::size_t idx) const noexcept { return m_marks[idx]; }

		void draw(int number) {
			for (std::size_t i = 0; i < m_boards.size(); ++i) {
				mark_board(i, number);
			}
		}

		std::optional<int> get_winning_board_index() {
			for (int i = 0; i < m_boards.size(); ++i) {
				if (check_rows(m_marks[i]) || check_columns(m_marks[i])) {
					return i;
				}
			}
			return std::nullopt;
		}
	private:
		void mark_board(std::size_t boardIdx, int number) {
			for (int row = 0; row < BingoBoard::Rows; ++row) {
				for (int column = 0; column < BingoBoard::Columns; ++column) {
					if (m_boards[boardIdx](row, column) == number) {
						m_marks[boardIdx](row, column) = true;
					}
				}
			}
		}

		bool check_rows(BingoBoardMarks const& marks) {
			for (int row = 0; row < BingoBoard::Rows; ++row) {
				bool row_wins = true;
				for (int column = 0; column < BingoBoard::Columns; ++column) {
					if (!marks(row, column)) {
						row_wins = false;
						break;
					}
				}
				if (row_wins) return true;
			}
			return false;
		}

		bool check_columns(BingoBoardMarks const& marks) {
			for (int column = 0; column < BingoBoard::Columns; ++column) {
				bool column_wins = true;
				for (int row = 0; row < BingoBoard::Rows; ++row) {
					if (!marks(row, column)) {
						column_wins = false;
						break;
					}
				}
				if (column_wins) return true;
			}
			return false;
		}
	};

	namespace BingoSubSystem {

		struct BingoInstance {
			BingoGame game;
			std::vector<int> draws;
		};

		BingoInstance create_game(std::istream& input) {
			std::vector<int> draws;
			std::string line;
			std::getline(input, line);
			AoC::string_splits(line,
				[&](std::string_view split) {
					draws.push_back(AoC::parse_int(split));
				},
				',');
			std::getline(input, line);
			std::vector<BingoBoard> boards;
			BingoBoard board;
			while (std::getline(input, line)) {
				if (line.empty()) {
					boards.push_back(board);
				}
				else {
					int row = 0;
					auto parse_row_splits = [&, col = 0](std::string_view split) mutable { if(!split.empty()) board(row, col++) = AoC::parse_int(split); }; //skip empty splits, as single digit numbers are padded with space
					while (row < BingoBoard::Rows) {
						AoC::string_splits(line, parse_row_splits);
						++row;
						std::getline(input, line);
					}
				}
			}
			return { BingoGame{std::move(boards)}, std::move(draws) }; //we assume this expr fails to trigger NRVO so we move out
		}

	}



	inline int star_one(std::istream& input)
	{
		auto [game, draws] = BingoSubSystem::create_game(input);
		for (int draw : draws) {
			game.draw(draw);
			auto const winning_index = game.get_winning_board_index();
			if (winning_index.has_value()) {
				BingoBoard const& winner = game.get_board(winning_index.value());
				BingoBoardMarks const& winner_marks = game.get_marks(winning_index.value());
				int score = 0;
				for (int i = 0; i < BingoBoard::NumElements; ++i) {
					if (!winner_marks.data[i]) {
						score += winner.data[i];
					}
				}
				return score * draw;
			}
		}
		return 0;
	}

	inline int star_two(std::istream& input)
	{
		auto [game, draws] = BingoSubSystem::create_game(input);

		return 0;
	}

}
