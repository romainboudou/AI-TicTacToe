#pragma once

#include "Player.h"

class HumanPlayer : public Player {

public: 
	HumanPlayer(const std::string& name, char symbol);

	std::pair<int, int> chooseMove(const Board& board) override;
};

