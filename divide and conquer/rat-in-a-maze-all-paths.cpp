/*
You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from position (i,j), down or right on the grid.
Initially rat is on the position (1,1). It wants to reach position (N,M). Find the rightmost path through which, rat can reach this position. A path is rightmost, if the rat is at position (i,j), it will always move to (i,j+1), if there exists a path from (i,j+1) to (N,M).

Input Format
First line contains 2 integers, N and M, denoting the rows and columns in the grid. Next N line contains. M characters each. An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.

Constraints
1<=N,M<=1000 GRID(i,j)='X' or 'O'

Output Format
If a solution exists: Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and a 0 denotes that the cell is not covered in the path.
If solution doesn't exist, just print "-1".

Sample Input
5 4
OXOO
OOOX
OOXO
XOOO
XXOO
Sample Output
1 0 0 0 
1 1 0 0 
0 1 0 0 
0 1 1 1 
0 0 0 1 
*/

//rat in a maze - print all paths

#include <bits/stdc++.h>
using namespace std;
bool solve(vector<vector<char>> &grid, int &n, int &m, vector<vector<bool>> &out, int i = 0, int j = 0) {
    if (i > n-1 || j > m-1) {
        return false;
    }
    if (grid[i][j] == 'X') {
        return false;
    }
    out[i][j] = true;
    if (i == n-1 && j == m-1) {
        //print output
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < m; q++) {
                cout << out[p][q] << " ";
            }
            cout << endl;
        }
        cout << "-------\n";
        out[i][j] = false;
        return true;
    }
    //try the right path
    bool right = false, down = false;
    right = solve(grid, n, m, out, i, j + 1);
    down = solve(grid, n, m, out, i + 1, j);
    out[i][j] = false;
    return right || down;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char> (m, 'O'));
    vector<vector<bool>> out(n, vector<bool> (m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    bool isSolved = solve(grid, n, m, out);
    if (!isSolved) {
        cout << "-1\n";
    }
    return 0;
}
