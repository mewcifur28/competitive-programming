// https://www.spoj.com/problems/FAVDICE/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        double ans = 0;
        for (ll i = 1; i <= n; i++) {
            ans += (1/(i * 1.0));
        }
        ans *= n;
        cout << fixed << setprecision(2) << ans << "\n";
    }
}
