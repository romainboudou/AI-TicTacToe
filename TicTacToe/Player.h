#pragma once

#include <string>
#include "Board.h"

class Player {

private:
	std::string name;
	char symbol;

public:
	Player(const std::string& name, char symbol);
	virtual ~Player() = default;

	//Getters
	std::string getName() const;
	char getSymbol() const;

	virtual std::pair<int, int> chooseMove(const Board& board = 0);
};

