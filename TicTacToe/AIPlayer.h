#pragma once

#include "Player.h"

class AIPlayer : public Player {

private:
	int minmax(Board board, int depth, bool isMaximizing, char symbol, char opponentSymbol, int alpha, int beta);
	bool checkWin(const Board& board, char symbol) const;

public: 
	AIPlayer(const std::string& name, char symbol);
	
	std::pair<int, int> chooseMove(const Board& board) override;
};

