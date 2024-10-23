#include "Game.h"
#include "Player.h"

int main() {
	Player player1("Romain", 'X');
	Player player2("Julen", 'O');

	Game tictactoe(player1, player2);
	tictactoe.start();

	return 0;
}