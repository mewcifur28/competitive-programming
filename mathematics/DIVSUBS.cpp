// https://www.codechef.com/problems/DIVSUBS
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while (t--) {
        bool found = false;
        ll n;
        cin >> n;
        unordered_map<ll, pair<ll, vector<ll>>> m;
        vector<ll> v(n), cs(n+1, 0);//, freq(n, 0);
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
        }
        //freq[0]++;
        m.insert({0, {1, {0}}});
        cs[1] = v[0] % n;
        cs[1] = (cs[1] + n) % n;
        //freq[cs[1]]++;
        m[cs[1]].first++;
        m[cs[1]].second.push_back(1);
        for (ll i = 2; i <= n; i++) {
            cs[i] = v[i-1] + cs[i-1];
            cs[i] = cs[i] % n;
            cs[i] = (cs[i] + n) % n; // for negative numbers;
            //freq[cs[i]]++;
            m[cs[i]].first++;
            m[cs[i]].second.push_back(i);
        }  
        for (auto p: m) {
            // cout << "element: " << p.first << " : #" << p.second.first << " : ";
            // for (auto v: p.second.second) {
            //     cout << v << ", ";
            // }
            // cout << "\n";

            if (p.second.first > 1) {
                ll i = p.second.second[0], j = p.second.second[1];
                cout << j - i << "\n";
                for (ll k = i; k < j; k++) {
                    cout << k + 1 << " ";
                }
                cout << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "-1\n";
        }
    }
    return 0;
}
