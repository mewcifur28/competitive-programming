// https://www.spoj.com/problems/DEFKIN/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll xmax, ymax, n;
        cin >> xmax >> ymax >> n;
        vector<ll> x(n+2, 0), y(n+2, 0);
        for (ll i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }
        x[n+1] = xmax+1, y[n+1] = ymax+1;
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        ll dx = 0, dy = 0;
        for (ll i = 0; i <= n; i++) {
            dx = max(dx, x[i+1] - x[i] - 1);
            dy = max(dy, y[i+1] - y[i] - 1);
        }
        cout << dx*dy << "\n";
    }
    return 0;
}
