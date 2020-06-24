#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

int main() {
    ll n, ans = 0;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        c[i] = a[i] - b[i];
    }
    PBDS s;
    for (int i = 0; i < n; i++) {
        ans += (s.size() - s.order_of_key({-c[i], INT_MAX}));
        s.insert({c[i], i});
    }
    cout << ans;
    return 0;
}
