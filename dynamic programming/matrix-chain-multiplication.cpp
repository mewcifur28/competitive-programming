#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mcm(ll n, vector<ll> &arr, vector<vector<ll>> &dp) {
    for (ll i = 1; i < n - 1; i++) {
        ll r = 0, c = i;
        while (r < n-1 && c < n-1) {
            ll currAns = LLONG_MAX;
            for (ll k = r; k < c; k++) {
                currAns = min(currAns, dp[r][k] + dp[k+1][c] + (arr[r] * arr[k+1] * arr[c+1]));
            }
            dp[r][c] = currAns;
            // cout << "dp[" << r << "][" << c << "] = " << dp[r][c] << "\n";
            r++;
            c++;
        }
    }
    return dp[0][n-2];
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<vector<ll>> dp(n-1, vector<ll> (n-1, 0));
        cout << mcm(n, arr, dp) << "\n";
    }
}
