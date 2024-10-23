#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

int main() {
	HumanPlayer player1("Romain", 'X');
	HumanPlayer player2("Julen", 'O');
	AIPlayer aiPlayer("IA", 'O');

	Game game(&player1, &aiPlayer);
	Game game2(&player1, &player2);
	game.start();
	//game2.start();

	return 0;
}