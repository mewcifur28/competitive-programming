#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n;
    cin >> n;
    vector<ll> dp(n);
    dp[0] = 0, dp[1] = 1;
    for (ll i = 2; i < n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n-1];
    return 0;
}