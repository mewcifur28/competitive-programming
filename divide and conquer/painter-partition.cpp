/*
Given K painters to paint N boards where each painter takes 1 unit of time to paint 1 unit of boards i.e. if the length of a particular board is 5, it will take 5 units of time to paint the board. Compute the minimum amount of time to paint all the boards.

Note that:

Every painter can paint only contiguous segments of boards.
A board can only be painted by 1 painter at maximum.
Input Format
First line contains K which is the number of painters. Second line contains N which indicates the number of boards. Third line contains N space separated integers representing the length of each board.

Constraints
1 <= K <= 10
1 <= N <= 10
1<= Length of each Board <= 10^8

Output Format
Output the minimum time required to paint the board.

Sample Input
2
2
1 10
Sample Output
10
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isEnoughTime(int paintersGiven, int numOfBoards, vector<int> &boards, ll timeTaken, ll areaGiven) {
    ll currentPainter = boards[0], paintersNeeded = 1, areaPainted = boards[0], lastBoard = 0;
    for (int i = 1; i < numOfBoards; i++) {
        if (boards[i] > timeTaken) {
            return false;
        }
        if (currentPainter + boards[i] > timeTaken) {
            currentPainter = 0;
            paintersNeeded++;
            lastBoard = i-1;
            i--;
        }
        else {
            currentPainter += boards[i];
            areaPainted += boards[i];
            lastBoard = i;
        }
    }/*
    if (lastBoard < numOfBoards - 1) {
        if (currentPainter + boards[numOfBoards - 1] > timeTaken) {
            return false;
        }

    }*/
    //cout << timeTaken << " " << paintersNeeded << " " << areaPainted << "\n";
    return (paintersGiven >= paintersNeeded) && areaPainted >= areaGiven && lastBoard == numOfBoards - 1;
}
ll calcTime(int numOfPainters, int numOfBoards, vector<int> &boards, ll s, ll e, ll area) {
    ll timeTaken = e;
    while (s <= e) {
        ll m = s + (e-s)/2;
        if (isEnoughTime(numOfPainters, numOfBoards, boards, m, area)) {
            timeTaken = m;
            e = m - 1;
        }
        else {
            s = m + 1;
        }
    }
    return timeTaken;
}
int main() {
    int numOfPainters, numOfBoards;
    cin >> numOfPainters >> numOfBoards;
    vector<int> boards(numOfBoards);
    ll sum = 0;
    for (int i = 0; i < numOfBoards; i++) {
        cin >> boards[i];
        sum += boards[i];
    }
    cout << calcTime(numOfPainters, numOfBoards, boards, 0, sum, sum);
    return 0;
}