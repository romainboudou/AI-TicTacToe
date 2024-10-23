#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

int main() {
	int choice;

	std::cout << "Choisissez le mode de jeu:\n";
	std::cout << "1. Jouer contre un autre joueur\n";
	std::cout << "2. Jouer contre l'IA\n";
	std::cout << "Entrez votre choix (1 ou 2): ";
	std::cin >> choice;

	std::string playerName1;
	std::cout << "Entrez le nom du joueur 1: ";
	std::cin >> playerName1;
	HumanPlayer player1(playerName1, 'X');

	if (choice == 1) {
		std::string playerName2;
		std::cout << "Entrez le nom du joueur 2: ";
		std::cin >> playerName2;
		HumanPlayer player2(playerName2, 'O');
		Game game(&player1, &player2);
		game.start();
	}
	else if (choice == 2) {
		AIPlayer player2("AI", '0');
		Game game(&player1, &player2);
		game.start();
	}
	else {
		std::cout << "Mauvais choix, le jeu va se stopper...";
		return 1;
	}

	return 0;
}