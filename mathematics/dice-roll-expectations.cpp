// In a game of fair dice(6 sides) throw, what is the expected number of throws to make sure that all 6 outcomes appear atleast once? Round off the ans to next integer.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t = 1;
    while (t--) {
        ll n = 6;
        float ans = 0;
        for (ll i = 1; i <= n; i++) {
            ans += (1/(i * 1.0));
        }
        ans *= n;
        cout << ceil(ans);
    }
}