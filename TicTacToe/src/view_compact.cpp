#include "../include/view.hpp"

void tictactoe::ViewCompact::Print(Game& game)
{
	const Matrix& matrix = game.GetField();
	std::cout << std::endl;
	for (auto& line : matrix) {
		std::string answer;
		for (auto j : line) {
			if (j == OptionalPlayer::Zero) {
				answer += "O";
			}
			else if (j == OptionalPlayer::Cross) {
				answer += "X";
			}
			else {
				answer += ".";
			}
		}
		std::cout << answer << std::endl;
	}
}