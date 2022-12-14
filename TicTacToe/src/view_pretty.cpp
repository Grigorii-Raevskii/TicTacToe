#include "../include/view.hpp"

void tictactoe::ViewPretty::Print(Game& game)
{
	const Matrix& matrix = game.GetField();
	std::cout << std::endl;
	std::string rowDelemiter = "  +----+----+----+----+----+----+----+----+----+----+";
	for (int i = 9; i >= 0; i--) {
		std::string mainLine = std::to_string(i) + " ", subLine = "  ";
		std::cout << rowDelemiter << std::endl;
		for (int j = 0; j < 10; j++) {
			if (matrix[j][i] == OptionalPlayer::Zero) {
				mainLine += "| @@ ";
				subLine += "| @@ ";
			}
			else if (matrix[j][i] == OptionalPlayer::Cross) {
				mainLine += "| \\/ ";
				subLine += "| /\\ ";
			}
			else {
				mainLine += "|    ";
				subLine += "|    ";
			}
		}
		std::cout << mainLine << "|" << std::endl;
		std::cout << subLine << "|" << std::endl;
	}
	std::cout << rowDelemiter << std::endl;
	std::cout << "    a    b    c    d    e    f    g    h    i    j " << std::endl;
}
