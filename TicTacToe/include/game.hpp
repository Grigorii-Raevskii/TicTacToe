#ifndef GAME_HPP_
#define GAME_HPP_
#include <sstream>
#include <regex>

namespace tictactoe {
	const int size = 10;
	class Game {
		enum OptionalPlayer {
			Cross, Zero, Empty
		};
		enum StateGame {
			BadMove, GoodMove, Exit, Win, CompactView, PrettyView, Draw
		};
	private:
		OptionalPlayer field[size][size] = { Empty };
		OptionalPlayer currentPlayer = OptionalPlayer::Zero;
		void Move(int x, int y);
	public:
		bool HasNextStep(); // ???
		bool CheckWin();
		StateGame ParseCommand(std::string command);
	};
}

#endif