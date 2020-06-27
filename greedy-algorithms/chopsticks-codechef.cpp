// https://www.codechef.com/problems/TACHSTCK

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t = 1;
    while (t--) {
        ll n, diff, pairs = 0;
        cin >> n >> diff;
        vector<ll> chopsticks(n);
        for (int i = 0; i < n; i++) {
            cin >> chopsticks[i];
        }
        sort(chopsticks.begin(), chopsticks.end());
        for (int i = 0; i < n-1; i++) {
            if (chopsticks[i+1] - chopsticks[i] <= diff) {
                pairs++;
                i++;
            }
        }
        cout << pairs;
    }
    return 0;
}
