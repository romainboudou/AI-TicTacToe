#pragma once

#include "Board.h"
#include "Player.h"

class Game {

private:
	Board board;
	Player* player1; 
	Player* player2;
	Player* currentPlayer;

	bool checkWin(char symbol) const;
	bool checkDraw() const;

public:
	Game(Player* p1, Player* p2);
	void start();
};

