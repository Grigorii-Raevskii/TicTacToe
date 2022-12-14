#include "../include/game.hpp"
#include <stdexcept>
using namespace tictactoe;

tictactoe::StateGame tictactoe::Game::Move(int x, int y)
{
	if (x < 0 || y < 0 || x >= size || y >= size || field[x][y] != Empty)
		return BadMove;
	field[x][y] = currentPlayer;
	moveCount++;
	return StateGame::Move;
}

tictactoe::StateGame tictactoe::Game::CheckWin()
{
	// TODO: Доделать Win
	int count = 0;
	int x = lastMoveX;
	int y = lastMoveY;
	// Проверка по вертикали
	while (x - 1 > 0 && field[x - 1][y] == field[lastMoveX][lastMoveY]) {
		x--;
	}
	while (field[x][y] == field[lastMoveY][lastMoveY]) {
		count++;
		x++;
		if (count == 4) {
			return (field[x][y] == OptionalPlayer::Cross ? XWin : OWin);
		}
	}
	// Проверка по горизонтали

	// Проверка по диагонали
	return StateGame::Move;
}

tictactoe::StateGame tictactoe::Game::ParseCommand(std::string command)
{
	std::smatch m;
	int x, y;
	const std::regex rCommandView(R"(view-\w+)");
	const std::regex rCompactCoord(R"(-?0*\d -?0*\d)");
	const std::regex rPrettyCommand(R"([a-j]\d)");
	boost::algorithm::trim(command);
	if (std::regex_match(command, m, rCommandView)) {
		if (command.compare("view-pretty")) {
			return PrettyView;
		}
		else if (command.compare("view-compact")) {
			return CompactView;
		}
	}
	if (std::regex_match(command, m, rCompactCoord)) {
		currentView = CompactView;
		std::stringstream ss(command);
		ss >> x >> y;
		if (x == -1 && y == -1)
			return Exit;
		return Move(x, y);
		// ???
		//CheckWin();
	}
	if (std::regex_match(command, m, rPrettyCommand)) {
		currentView = PrettyView;
		x = command[0] - 'a';
		y = command[1] - '0';
		return Move(x, y);
		//CheckWin();
	}
	return StateGame::Move;
}

OptionalPlayer tictactoe::Game::GetCurrentPlayer()
{
	return currentPlayer;
}

Matrix tictactoe::Game::GetField() const
{
	return this->field;
}

void tictactoe::Game::SwapPlayer()
{
	currentPlayer = (OptionalPlayer)((currentPlayer + 1) % 2);
}

StateGame tictactoe::Game::GetCurrentView()
{
	return currentView;
}
