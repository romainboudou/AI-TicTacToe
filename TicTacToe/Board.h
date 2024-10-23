#pragma once

#include <vector>
#include <iostream>

class Board {
private:
    std::vector<std::vector<char>> board;
    int size;

public:
    Board(int size = 3);

    void displayBoard() const;
    bool placeSymbol(int row, int col, char symbol);
    char getSymbol(int row, int col) const;
    void resetBoard();
    bool isFull() const; 
};
