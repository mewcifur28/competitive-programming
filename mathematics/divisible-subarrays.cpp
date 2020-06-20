/*
You are given N elements, a1,a2,a3….aN. Find the number of good sub-arrays.
A good sub-array is a sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) is divisible by N.



Input Format
The first line contains the number of test cases T. First line of each test case contains an integer N denoting the number of elements. Second line of each test case contains N integers, a1, a2, a3….aN, where ai denotes the ith element of the array.

Constraints
1<=T<=10
1<=N<=10^5
|ai|<=10^9

Output Format
Output a single integer denoting the number of good sub-arrays.

Sample Input
2
5
1 1 1 1 1
5
5 5 5 5 5
Sample Output
1
15
Explanation
In first test case, there is only one sub-array [1, 1, 1, 1, 1], such that 1+1+1+1+1=5, which is divisible by N=5
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> v(n), cs(n+1, 0), freq(n, 0);
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
        }
        cs[1] = v[0] % n;
        cs[1] = (cs[1] + n) % n;
        freq[0]++;
        freq[cs[1]]++;
        for (ll i = 2; i <= n; i++) {
            cs[i] = v[i-1] + cs[i-1];
            cs[i] = cs[i] % n;
            cs[i] = (cs[i] + n) % n; // for negative numbers;
            freq[cs[i]]++;
        }
        // for (int i =0; i <= n; i++) {
        //     cout << cs[i] << " ";
        // }
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            //cout << freq[i] << " ";
            if (freq[i] < 2) {
                continue;
            }
            ans += ((freq[i] * (freq[i]-1))/2);
        }
        cout << ans << "\n";
    }
    return 0;
}
