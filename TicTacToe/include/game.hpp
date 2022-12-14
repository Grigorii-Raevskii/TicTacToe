#ifndef GAME_HPP_
#define GAME_HPP_
#include <sstream>
#include <regex>
#include <memory>
#include <boost/algorithm/string/trim.hpp>

namespace tictactoe {
	const int size = 10;
	enum OptionalPlayer {
		Cross, Zero, Empty
	};
	enum StateGame {
		BadMove, Exit, CompactView, PrettyView, Draw, OWin, XWin, Move
	};
	typedef std::vector<std::vector<OptionalPlayer>> Matrix;
	class Game {
	private:
		int moveCount = 0;
		Matrix field = Matrix(size, std::vector<OptionalPlayer>(size, OptionalPlayer::Empty));
		OptionalPlayer currentPlayer = OptionalPlayer::Zero;
		StateGame Move(int x, int y);
		StateGame currentView = CompactView;
		int lastMoveX;
		int lastMoveY;
	public:
		StateGame CheckWin();
		StateGame ParseCommand(std::string command);
		OptionalPlayer GetCurrentPlayer();
		Matrix GetField() const;
		void SwapPlayer();
		StateGame GetCurrentView();
	};
}

#endif