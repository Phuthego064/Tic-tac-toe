

#include <iostream>

import game;


using namespace std;

int main() {
    initializeBoard();
    char currentPlayer = 'X';
    int row, col;

    cout << "Welcome to Tic Tac Toe!\n";
    displayBoard();

    while (true) {
		
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;
		
        // Validate move
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Place move
        board[row][col] = currentPlayer;
        displayBoard();

        // Check win
        if (checkWin(currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check draw
        if (checkDraw()) {
            cout << "It's a draw!\n";
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
		

    }

    return 0;
}