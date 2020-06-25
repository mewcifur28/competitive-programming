#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll pow(ll a,ll b)
{
    ll ans=1;
    for(;b > 0;a = a * a ,b >>= 1)if(b & 1)ans = ans * a ;
    return ans;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, temp;
        cin >> n;
        temp = n;
        vector<pair<ll, ll>> primes;
        for (ll i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                ll count = 0;
                while (n % i == 0) {
                    n /= i;
                    count++;
                }
                primes.push_back({i, count});
            }
        }
        if (n > 1) {
            ll count = 0, i = n;
            while (n > 1) {
                n /= i;
                count++;
            }
            primes.push_back({i, count});
        }
        if (primes.size() == 1) {
            if (primes[0].second < 6) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n" << pow(primes[0].first, 1) << " " << pow(primes[0].first, 2) << " " << pow(primes[0].first, (primes[0].second - 3)) << "\n";
            }
        }
        else if (primes.size() == 2) {
            if ((primes[0].second + primes[1].second) < 4) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n" << primes[0].first << " " << primes[1].first << " " << pow(primes[0].first, primes[0].second - 1) * pow(primes[1].first, primes[1].second - 1) << "\n";
            }
        }
        else {
            cout << "YES\n" << pow(primes[0].first, primes[0].second) << " " << pow(primes[1].first, primes[1].second) << " ";
            temp = temp / pow(primes[0].first, primes[0].second);
            temp = temp / pow(primes[1].first, primes[1].second);
            cout << temp << "\n";
        }
    }
    return 0;
}
