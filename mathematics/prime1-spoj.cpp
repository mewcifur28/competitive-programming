// https://www.spoj.com/problems/PRIME1/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> primes;

void makeSieve() {
    ll n = 100000;
    vector<bool> sieve(n, true);
    sieve[0] = sieve[1] = false;
    for (ll i = 2; i < n; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            for (ll j = i*i; j < n; j += i) {
                sieve[j] = false;
            }
        }
    }
}

int main() {
    makeSieve();
    ll t;
    cin >> t;
    while (t--) {
        ll m, n;
        cin >> m >> n;
        vector<bool> segment(n-m+1, true);
        for (auto prime: primes) {
            //mark all the multiples of prime in "segment" as false

            //optimisation
            if (prime*prime > n) {
                break;
            }

            ll start = (m/prime) * prime;

            //corner case
            if (prime >= m && prime <= n) {
                start = prime * 2;
            }

            //actual work
            for (ll i = start; i <= n; i += prime) {
                if (i-m >= 0)
                    segment[i-m] = false;
            }
        }
        for (ll i = m; i <= n; i++) {
            if (i-m >= 0) {
                if (segment[i-m] && i != 1) {
                    cout << i << "\n";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
