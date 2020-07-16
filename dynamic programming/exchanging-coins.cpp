/*
Tughlaq introduces a strange monetary system. He introduces copper coins and each coin has a number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. A coin can also be sold for gold. One can get as much grams of gold as the number written on the coin. You have one copper coin. What is the maximum weight of gold one can get from it?

Input Format
The input file contains a single integer n, the number on the coin.

Constraints
0 <= n <= 1 000 000 000

Output Format
Print the maximum weight of gold you can get.

Sample Input
12
Sample Output
13
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll maxGold(ll n, unordered_map<ll, ll> &dp) {
    if (n <= 0) {
        return 0;
    }
    if (dp.find(n) != dp.end()) {
        return dp[n];
    }
    dp[n] = max(n, maxGold(n/2, dp) + maxGold(n/3, dp) + maxGold(n/4, dp));
    return dp[n];
}
int main() {
    ll n;
    cin >> n;
    unordered_map<ll, ll> dp;
    cout << maxGold(n, dp);
    return 0;
}
