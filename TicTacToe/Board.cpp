#include "Board.h"

Board::Board(int size) : size(size), board(size, std::vector<char>(size, ' ')) {}

void Board::displayBoard() const {
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            std::cout << " ";
            std::cout << board[row][col];
            if (col < size - 1) std::cout << " | ";
        }
        std::cout << std::endl;
        if (row < size - 1) {
            std::cout << "------------";
            std::cout << std::endl;
        }
    }
}

bool Board::placeSymbol(int row, int col, char symbol) {
    if (row >= 0 && row < size && col >= 0 && col < size && board[row][col] == ' ') {
        board[row][col] = symbol;
        return true;
    }
    return false;
}

char Board::getSymbol(int row, int col) const {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        return board[row][col];
    }
    return ' ';
}

void Board::resetBoard() {
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            board[row][col] = ' ';
        }
    }
}

bool Board::isFull() const {
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (board[row][col] == ' ') {
                return false;
            }
        }
    }
    return true;
}