#include "Board.h"

int main() {
	Board board;
	
    std::cout << "Plateau initial:" << std::endl;
    board.displayBoard();

    board.placeSymbol(0, 0, 'X');
    board.placeSymbol(1, 1, 'O');
    board.placeSymbol(0, 1, 'X');
    board.placeSymbol(2, 2, 'O');

    std::cout << "\nPlateau apres quelques coups:" << std::endl;
    board.displayBoard();

    char symbolAtPosition = board.getSymbol(1, 1);
    std::cout << "\nSymbole a la position (1, 1): " << symbolAtPosition << std::endl;

    bool isFull = board.isFull();
    std::cout << "Le plateau est-il plein? " << (isFull ? "Oui" : "Non") << std::endl;

    board.resetBoard();
    std::cout << "\nPlateau après reinitialisation:" << std::endl;
    board.displayBoard();

	return 0;
}