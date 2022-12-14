//#include <boost/dll/import.hpp>
#include <boost/version.hpp>
#include "../include/game.hpp"
#include "../include/view.hpp"
#include <iostream>
#include <string>
#include <map>
using namespace tictactoe;
#if BOOST_VERSION >= 107600
// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define boost_dll_import_symbol ::boost::dll::import_symbol
#else
// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define boost_dll_import_symbol ::boost::dll::import
#endif

int main(int argc, char** argv) {
	bool isRun = true;
	Game game;
	std::map<StateGame, View*> views{ {CompactView, new ViewCompact()}, {PrettyView, new ViewPretty()} };
	View* view;
	// Идея как выводить пустое поле вначале
	// Произвели ход, но не меняем матрицу.
	// 
	while (isRun) {
		std::string command;
		std::getline(std::cin, command);
		StateGame state = game.ParseCommand(command);
		view = views[game.GetCurrentView()];
		switch (state)
		{
		case BadMove:
			std::cout << "Bad move!" << std::endl;
			break;
		case Exit:
			isRun = false;
			break;
		case CompactView:
			view = views[CompactView];
			break;
		case PrettyView:
			view = views[PrettyView];
			break;
		case Draw:
			std::cout << "Draw." << std::endl;
			break;
		case OWin:
			std::cout << "O wins!" << std::endl;
			break;
		case XWin:
			std::cout << "X wins!" << std::endl;
			break;
		case Move:
			view->Print(game);
			game.SwapPlayer();
			std::cout << (game.GetCurrentPlayer() == OptionalPlayer::Zero ? "O move:" : "X move:");
			break;
		}
	}

	return 0;
}
