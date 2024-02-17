#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<string>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if the current player has won
bool checkWin(const vector<vector<string>>& board, const string& player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<string>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == "-") {
                return false; // Game is not a draw, still empty cell left
            }
        }
    }
    return true; // Game is a draw
}

// Function to play the Tic-Tac-Toe game
void playGame() {
    vector<vector<string>> board(3, vector<string>(3, "-")); // Initialize empty board
    string currentPlayer = "X"; // Start with player X
    
    // Game loop
    while (true) {
        // Display the board
        cout << "Current board:" << endl;
        displayBoard(board);
        
        // Get player input
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        
        // Update the board
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == "-") {
            board[row][col] = currentPlayer;
            
            // Check for win
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break; // End the game
            }
            
            // Check for draw
            if (checkDraw(board)) {
                cout << "It's a draw!" << endl;
                break; // End the game
            }
            
            // Switch players
            currentPlayer = (currentPlayer == "X") ? "O" : "X";
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }
}

int main() {
    // Play the game
    playGame();
    
    // Ask if players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        main(); // Start the game again
    }
    
    return 0;
}
