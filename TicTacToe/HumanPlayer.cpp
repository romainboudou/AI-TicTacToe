#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(const std::string& name, char symbol) : Player(name, symbol) {}

std::pair<int, int> HumanPlayer::chooseMove(const Board& board) {
	int row, col;
	while (true) {
		std::cout << getName() << " entrez la ligne et la colonne (0-2) : ";
		std::cin >> row >> col;

		if (board.getSymbol(row, col) == ' ') {
			return { row, col };
		}
		else {
			std::cout << "Emplacement invalide. Reessayez." << std::endl;
		}
	}
}