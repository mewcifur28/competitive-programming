#include <bits/stdc++.h>
using namespace std;
bool isValidPos(vector<vector<bool>> &board, int n, int x, int y) {
    for (int i = 0; i < n; i++) {
        if (board[i][y] == true || board[x][i] == true) {
            return false;
        }
    }
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == true) {
            return false;
        }
    }
    for (int i = x, j = y; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == true) {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<bool>> &board, int n, int &count, int i = 0) {
    if (i >= n) {
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < n; q++) {
                cout << board[p][q] << " ";
            }
            cout << "\n";
        }
        for (int p = 0; p < n; p++) {
            cout << "- ";
        }
        cout << "\n";
        count++;
        return true;
    }
    for (int j = 0; j < n; j++) {
        if (isValidPos(board, n, i, j)) {
            board[i][j] = true;
            bool isSolved = solve(board, n, count, i + 1);
            /*if (isSolved) {
                return true;
            }*/ // remove the comments to print only 1 config
            board[i][j] = false;
        }
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    int count = 0;
    solve(board, n, count);
    cout << count;
    return 0;
}
