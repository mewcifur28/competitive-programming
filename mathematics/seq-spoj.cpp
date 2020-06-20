// https://www.spoj.com/problems/SEQ/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> matrixMultiplication(vector<vector<ll>> m1, vector<vector<ll>> m2) {
    ll p = m1.size(), q = m1[0].size(), r = m2.size(), s = m2[0].size();
    vector<vector<ll>> m3(p, vector<ll> (s, 0));
    for (ll i = 0; i < p; i++) {
        for (ll k = 0; k < s; k++) {
            ll sum = 0;
            for (ll j = 0; j < q; j++) {
                sum += m1[i][j]*m2[j][k];
                sum = sum % 1000000000;
            }
            m3[i][k] = sum;
        }
    }
    return m3;
}
vector<vector<ll>> fastPowerMatrix(vector<vector<ll>> M, ll pow, ll order) {
    if (pow == 0) {
        vector<vector<ll>> I(order, vector<ll>(order, 0));
        for (ll i = 0; i < order; i++) {
            I[i][i] = 1;
        }
        return I;
    }
    vector<vector<ll>> smallAns = fastPowerMatrix(M, pow/2, order);
    smallAns = matrixMultiplication(smallAns, smallAns);
    if (pow & 1) {
        smallAns = matrixMultiplication(M, smallAns);
    }
    return smallAns;
}
ll findAns(ll k, vector<ll> &b, vector<ll> &c, ll n) {
    if (n < k) {
        return b[n];
    }
    vector<vector<ll>> T(k, vector<ll>(k, 0)), a;
    for (ll i = 0; i < k-1; i++) {
        T[i][i+1] = 1;
    }
    for (ll i = 0; i < k; i++) {
        T[k-1][i] = c[k-i-1];
    }
    T = fastPowerMatrix(T, n, k);
    vector<vector<ll>> B(b.size(), vector<ll> (1, 0));
    for (int i = 0; i < k; i++) {
        B[i][0] = b[i];
    }
    a = matrixMultiplication(T, B);
    return a[0][0] % 1000000000;
    return 0;
}
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll k, n;
        cin >> k;
        vector<ll> b(k), c(k);
        for (ll i = 0; i < k; i++) {
            cin >> b[i];
        }
        for (ll i = 0; i < k; i++) {
            cin >> c[i];
        }
        cin >> n;
        cout << findAns(k, b, c, n-1) << "\n";
    }
    return 0;    
}
