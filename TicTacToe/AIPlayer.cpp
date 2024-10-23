#include "AIPlayer.h"
#include <limits>

AIPlayer::AIPlayer(const std::string& name, char symbol) : Player(name, symbol) {}

bool AIPlayer::checkWin(const Board& board, char symbol) const {
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

// Minimax avec élagage alpha-bêta
int AIPlayer::minmax(Board board, int depth, bool isMaximizing, char symbol, char opponentSymbol, int alpha, int beta) {
    if (checkWin(board, symbol)) {
        return 10 - depth; // IA gagne
    }
    if (checkWin(board, opponentSymbol)) {
        return depth - 10; // Adversaire gagne
    }
    if (board.isFull()) {
        return 0; // Match nul
    }

    if (isMaximizing) {
        int bestValue = std::numeric_limits<int>::min();
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (board.getSymbol(row, col) == ' ') {
                    board.placeSymbol(row, col, symbol);
                    int value = minmax(board, depth + 1, false, symbol, opponentSymbol, alpha, beta);
                    bestValue = std::max(bestValue, value);
                    alpha = std::max(alpha, value);
                    if (beta <= alpha) break; // Élagage
                    board.resetSymbol(row, col);
                }
            }
        }
        return bestValue;
    }
    else {
        int bestValue = std::numeric_limits<int>::max();
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (board.getSymbol(row, col) == ' ') {
                    board.placeSymbol(row, col, opponentSymbol);
                    int value = minmax(board, depth + 1, true, symbol, opponentSymbol, alpha, beta);
                    bestValue = std::min(bestValue, value);
                    beta = std::min(beta, value);
                    if (beta <= alpha) break; // Élagage
                    board.resetSymbol(row, col);
                }
            }
        }
        return bestValue;
    }
}

std::pair<int, int> AIPlayer::chooseMove(const Board& board) {
    int bestValue = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove = { -1, -1 };
    char opponentSymbol = (getSymbol() == 'X') ? 'O' : 'X'; 

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board.getSymbol(row, col) == ' ') {
                Board newBoard = board; 
                newBoard.placeSymbol(row, col, getSymbol());
                int moveValue = minmax(newBoard, 0, false, getSymbol(), opponentSymbol, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

                if (moveValue > bestValue) {
                    bestValue = moveValue;
                    bestMove = { row, col };
                }
            }
        }
    }

    std::cout << getName() << " a joue." << std::endl;

    return bestMove;
}
