#include <iostream>
#include <vector>

using namespace std;

int count = 0;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}
void solveNQueens(vector<vector<int>>& board, int row, int n, int k) {
    if (k == 0) {
        count++;
        return;
    }

    if (row == n) {
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            solveNQueens(board, row + 1, n, k - 1);
            board[row][col] = 0;
        }
    }
    solveNQueens(board, row + 1, n, k);
}

int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    vector<vector<int>> board(n, vector<int>(n, 0));

    solveNQueens(board, 0, n, k);

    cout << "Number of ways to place " << k << " queens on a " << n << "x" << n << " chessboard: " << count << endl;

    return 0;
}
