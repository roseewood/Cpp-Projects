#include <iostream>
using namespace std;

const int SIZE = 9;

int board[SIZE][SIZE] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

void printBoard() {
    cout << "-------------------------\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (j % 3 == 0) cout << "| ";
            if (board[i][j] == 0)
                cout << ". ";
            else
                cout << board[i][j] << " ";
        }
        cout << "|\n";
        if ((i + 1) % 3 == 0) cout << "-------------------------\n";
    }
}

bool isValid(int row, int col, int num) {
    for (int i = 0; i < SIZE; ++i) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool isComplete() {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (board[i][j] == 0)
                return false;
    return true;
}

// 🧠 Backtracking solver function
bool solve() {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (isValid(row, col, num)) {
                        board[row][col] = num;
                        if (solve())
                            return true;
                        board[row][col] = 0; // backtrack
                    }
                }
                return false; // trigger backtracking
            }
        }
    }
    return true; // solved
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Sudoku Game ---\n";
        printBoard();
        cout << "1. Enter a number\n";
        cout << "2. Solve automatically\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int row, col, num;
            cout << "Enter row (1-9), column (1-9), and number (1-9): ";
            cin >> row >> col >> num;
            row--; col--;
            if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || num < 1 || num > 9) {
                cout << "Invalid input. Try again.\n";
                continue;
            }
            if (board[row][col] != 0) {
                cout << "Cell already filled. Try a different cell.\n";
                continue;
            }
            if (isValid(row, col, num)) {
                board[row][col] = num;
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }
        else if (choice == 2) {
            if (solve()) {
                cout << "\nPuzzle solved!\n";
                printBoard();
            } else {
                cout << "No solution exists.\n";
            }
        }
        else if (choice == 3) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }

        if (isComplete()) {
            cout << "Congratulations! You completed the puzzle!\n";
            break;
        }
    }
    return 0;
}
