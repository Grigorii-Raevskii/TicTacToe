#include "../include/game.hpp"
#include <stdexcept>

bool tictactoe::Game::HasNextStep()
{
	return true;
}

void tictactoe::Game::Move(int x, int y)
{
	if (x < 0 || y < 0 || x >= size || y >= size || field[x][y] != Empty)
		throw std::exception("Bad move!");
	field[x][y] = currentPlayer;
	currentPlayer = (OptionalPlayer)((currentPlayer + 1) % 2);
}

tictactoe::Game::StateGame tictactoe::Game::ParseCommand(std::string command)
{
	std::smatch m;
	const std::regex rCommandView(R"(view-\w+)");
	const std::regex rCompactCoord(R"(-?\d -?\d)");
	const std::regex rPrettyCommand(R"([a-j]\d)");
	if (std::regex_match(command, m, rCommandView)) {

	}
	if (std::regex_match(command, m, rCompactCoord)) {
		int x, y;
		std::stringstream ss(command);
		ss >> x >> y;
		Move(x, y);
		//game.CheckWin();

	}
	if (std::regex_match(command, m, rPrettyCommand)) {

	}
	return StateGame();
}
