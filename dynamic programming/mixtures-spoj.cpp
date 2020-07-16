// https://www.spoj.com/problems/MIXTURES/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll calcCsum(ll s, ll e, vector<ll> &csum) {
    return (csum[e+1] - csum[s]) % 100;
}
ll findMinSmoke(ll n, vector<ll> &arr, vector<vector<ll>> &dp, vector<ll> &csum) {
    for (ll i = 1; i < n; i++) {
        ll r = 0, c = i;
        while (r < n && c < n) {
            ll currAns = LLONG_MAX;
            for (ll k = r; k < c; k++) {
                currAns = min(currAns, dp[r][k] + dp[k+1][c] + (calcCsum(r, k, csum) * calcCsum(k+1, c, csum)));
            }
            dp[r][c] = currAns;
            // cout << "dp[" << r << "][" << c << "] = " << dp[r][c] << "\n";
            r++;
            c++;
        }
    }
    return dp[0][n-1];
}
int main() {
    ll n;
    cin >> n;
    while (!cin.eof()) {
        vector<ll> arr(n), csum(n+1, 0);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            csum[i+1] = csum[i] + arr[i];
        }
        vector<vector<ll>> dp(n, vector<ll> (n, 0));
        cout << findMinSmoke(n, arr, dp, csum) << "\n";
        cin >> n;
    }
    return 0;
}
