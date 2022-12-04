//#include <boost/dll/import.hpp>
#include <boost/version.hpp>
#include "../include/game.hpp"
#include <iostream>
#include <string>
using namespace tictactoe;
#if BOOST_VERSION >= 107600
// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define boost_dll_import_symbol ::boost::dll::import_symbol
#else
// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define boost_dll_import_symbol ::boost::dll::import
#endif

int main(int argc, char** argv) {

	Game game;
	while (game.HasNextStep()) {
		std::string command;
		std::getline(std::cin, command);
		game.ParseCommand(command);
	}

	return 0;
}
