#ifndef VIEW_HPP_
#define VIEW_HPP_
#include "../include/game.hpp"
#include <iostream>

namespace tictactoe {
	class View {
	public:
		virtual void Print(Game& game) = 0;
	};

	class ViewCompact : public View
	{
		void Print(Game& game) override;
	};

	class ViewPretty : public View {
		void Print(Game& game) override;
	};
}

#endif