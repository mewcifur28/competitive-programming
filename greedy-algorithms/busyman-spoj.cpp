// https://www.spoj.com/problems/BUSYMAN/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool cmp (pair<ll, ll> p1, pair<ll, ll> p2) {
    return p1.second < p2.second;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<ll, ll>> timings(n);
        for (int i = 0; i < n; i++) {
            ll s, e;
            cin >> s >> e;
            timings[i] = {s, e};
        }
        sort(timings.begin(), timings.end(), cmp);
        int ans = 1;
        ll currEndTime = timings[0].second;
        for (int i = 1; i < n; i++) {
            if (timings[i].first >= currEndTime) {
                ans++;
                currEndTime = timings[i].second;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

