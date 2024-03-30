#include <iostream>
#include <vector>
#include <string>

// Function to display the Tic-Tac-Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if there is a winner
char checkWinner(const std::vector<std::vector<char>>& board) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];
    // If no winner, return space
    return ' ';
}

// Function to check if the board is full (draw)
bool isBoardFull(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false; // If there's an empty cell, game is not draw
        }
    }
    return true; // All cells filled, game is draw
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' ')); // Initialize empty board
    char currentPlayer = 'X'; // Player X starts

    std::cout << "Welcome to Tic-Tac-Toe!\n";

    while (true) {
        std::cout << "\nCurrent board:\n";
        displayBoard(board);

        // Get player input
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter row (1-3) and column (1-3) for your move: ";
        std::cin >> row >> col;

        // Adjust row and column to array indices
        row--;
        col--;

        // Check if the chosen cell is empty and within bounds
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            // Check for a winner
            char winner = checkWinner(board);
            if (winner != ' ') {
                std::cout << "\nPlayer " << winner << " wins!\n";
                break; // Game over
            }

            // Check for a draw
            if (isBoardFull(board)) {
                std::cout << "\nThe game is a draw!\n";
                break; // Game over
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "\nInvalid move! Please try again.\n";
        }
    }

    return 0;
}
