#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll nthFiboNum(ll n, vector<ll> &dp) {
    if (n < 0) {
        return 0;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    if (n == 0 || n == 1) {
        return dp[n] = n;
    }
    dp[n] = nthFiboNum(n-1, dp) + nthFiboNum(n-2, dp);
}
int main() {
    ll n;
    cin >> n;
    vector<ll> dp(n+1, -1);
    cout << nthFiboNum(n, dp);
    return 0;
}