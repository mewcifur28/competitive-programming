#include <bits/stdc++.h>
using namespace std;
bool isValidPos(vector<vector<bool>> &board, int n, int x, int y, unordered_map<int, bool> &col, unordered_map<int, bool> &diagSum, unordered_map<int, bool> &diagDiff) {
    if (col[y] == true || diagDiff[x-y] == true || diagSum[x+y] == true) {
        return false;
    }
    return true;
}
bool solve(vector<vector<bool>> &board, int n, int &count, unordered_map<int, bool> &col, unordered_map<int, bool> &diagSum, unordered_map<int, bool> &diagDiff, int i = 0) {
    if (i >= n) {
        /*for (int p = 0; p < n; p++) {
            for (int q = 0; q < n; q++) {
                cout << board[p][q] << " ";
            }
            cout << "\n";
        }
        for (int p = 0; p < n; p++) {
            cout << "- ";
        }
        cout << "\n";*/
        count++;
        return true;
    }
    for (int j = 0; j < n; j++) {
        if (isValidPos(board, n, i, j, col, diagSum, diagDiff)) {
            board[i][j] = true;
            col[j] = true;
            diagSum[i+j] = true;
            diagDiff[i-j] = true;
            bool isSolved = solve(board, n, count, col, diagSum, diagDiff, i + 1);
            /*if (isSolved) {
                return true;
            }*/ //remove brackets for single configuration
            //backtrack
            board[i][j] = false;
            col[j] = false;
            diagSum[i+j] = false;
            diagDiff[i-j] = false;
        }
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    unordered_map<int, bool> col, diagSum, diagDiff;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            col[j] = false;
            diagSum[i+j] = false;
            diagDiff[i-j] = false;
        }
    }
    int count = 0;
    solve(board, n, count, col, diagSum, diagDiff);
    cout << count;
    return 0;
}
