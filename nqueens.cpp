#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper-left diagonal
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper-right diagonal
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

void printBoard(const vector<vector<int>> &board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueensUtil(vector<vector<int>> &board, int row, int n) {
    if (row == n) {
        printBoard(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            solveNQueensUtil(board, row + 1, n);
            board[row][col] = 0; // backtrack
        }
    }
}

void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    solveNQueensUtil(board, 0, n);
}

int main() {
    int n = 4;
    solveNQueens(n);
    return 0;
}
