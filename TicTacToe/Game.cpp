#include "Game.h"

Game::Game(const Player& p1, const Player& p2) : player1(p1), player2(p2), currentPlayer(&player1) {}

bool Game::checkWin(char symbol) const {
    for (int row = 0; row < 3; ++row) {
        if (board.getSymbol(row, 0) == symbol &&
            board.getSymbol(row, 1) == symbol &&
            board.getSymbol(row, 2) == symbol) {
            return true;
        }
    }

    for (int col = 0; col < 3; ++col) {
        if (board.getSymbol(0, col) == symbol &&
            board.getSymbol(1, col) == symbol &&
            board.getSymbol(2, col) == symbol) {
            return true;
        }
    }

    if (board.getSymbol(0, 0) == symbol && board.getSymbol(1, 1) == symbol && board.getSymbol(2, 2) == symbol) {
        return true;
    }
    if (board.getSymbol(0, 2) == symbol && board.getSymbol(1, 1) == symbol && board.getSymbol(2, 0) == symbol) {
        return true;
    }

    return false;
}

bool Game::checkDraw() const {
    return board.isFull();
}

void Game::start() {
    while (true) {
        board.displayBoard();
        int row, col;
        std::cout << currentPlayer->getName() << " entre la ligne et la colonne (0 a 2) : ";
        std::cin >> row >> col;
        
        if (board.placeSymbol(row, col, currentPlayer->getSymbol())) {
            if (checkWin(currentPlayer->getSymbol())) {
                std::cout << currentPlayer->getName() << " win !" << std::endl;
                board.displayBoard();
                break;
            }
            if (checkDraw()) {
                std::cout << "C'est un match nul !" << std::endl;
                board.displayBoard();
                break;
            }
            currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
        }
        else {
            std::cout << "Emplacement invalide. Reessayez." << std::endl;
        }
    }
}