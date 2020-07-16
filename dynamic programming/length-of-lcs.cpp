/*
A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. For example, the sequence {A,B,D} is a subsequence of {A,B,C,D,E,F}, obtained after removal of elements C, E and F.

Given two strings A and B of size n and m respectively, you have to find the length of Longest Common Subsequence(LCS) of strings A and B, where LCS is the longest sequence present in both A and B.

Input Format
Two strings A and B.

Constraints
1 <= n,m <= 10^3

Output Format
Output the LCS of A and B.

Sample Input
abc
acd
Sample Output
2
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    ll n = s1.size(), m = s2.size();
    vector<vector<ll>> dp(n, vector<ll> (m, 0));
    for (ll i = 1; i < n; i++) {
        for (ll j = 1; j < m; j++) {
            dp[i][j] = (s1[i] == s2[j]) ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n-1][m-1];
}
