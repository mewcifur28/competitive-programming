// www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isValid(ll n, ll c, vector<ll> stalls, ll minDist) {
    ll prevCow = stalls[0];
    ll count = 1;
    for (ll i = 1; i < n; i++) {
        if (stalls[i] - prevCow >= minDist) {
            count++;
            prevCow = stalls[i];
            if (count == c) {
                return true;
            }
        }
    }
    return false;
}
ll findMinDist(ll &n, ll &c, vector<ll> &stalls) {
    ll s = 1, e = stalls[n - 1] - stalls[0], ans = 1;
    while (s <= e) {
        ll mid = s + (e-s)/2;
        if (isValid(n, c, stalls, mid)) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}
int main() {
    ll n, c;
    cin >> n >> c;
    vector<ll> stalls(n);
    for (ll i = 0; i < n; i++) {
        cin >> stalls[i];
    }
    sort(stalls.begin(),stalls.end());
    cout << findMinDist(n, c, stalls) << "\n";
    return 0;
}