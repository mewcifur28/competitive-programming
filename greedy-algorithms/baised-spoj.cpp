https://www.spoj.com/problems/BAISED/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> preferredRanks(n);
        for (ll i = 0; i < n; i++) {
            string s;
            cin >> s >> preferredRanks[i];
            preferredRanks[i]--; //make the ranks 0-based
        }
        sort(preferredRanks.begin(), preferredRanks.end()); //use count sort to do it O(n)
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            ans += abs(i-preferredRanks[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
