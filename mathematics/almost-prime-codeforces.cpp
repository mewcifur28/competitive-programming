#include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/26/A
using namespace std;
#define ll long long int
ll sieve(ll n) {
    vector<ll> primeDivisors(n+1, 0), primes;
    for (ll i = 2; i <= n; i++) {
        if (primeDivisors[i] == 0) {
            primes.push_back(i);
            for (ll j = i; j <= n; j += i) {
                primeDivisors[j]++;
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        if (primeDivisors[i] == 2) {
            ans++;
        }
    }
    return ans;
}
int main() {
    ll n;
    cin >> n;
    cout << sieve(n);
    return 0;
}
