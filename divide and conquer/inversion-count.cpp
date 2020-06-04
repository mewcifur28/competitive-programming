/*
You are given an array A find out number of pairs (i,j) in array A such that A[i] > A[j] and i < j.

Input Format
The first line consists of number of test cases t. Each test case consists of integer N followed by N space separated integers.

Constraints
1 <= N <= 100000 1 <= t <= 20 0 <= A[i] <= 100000000

Output Format
The number of inversions in array

Sample Input
2
4
1 2 4 3
3
3 2 1
Sample Output
1
3
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll findCrossInv(vector<ll> &v, ll s, ll e, ll mid) {
    ll count = 0, i = s, j = mid+1, k = 0;
    vector<ll> temp(e - s + 1);
    while (i <= mid && j <= e) {
        if (v[i] > v[j]) {
            temp[k++] = v[j++];
            count += (mid - i + 1);
        }
        else {
            temp[k++] = v[i++];
        }
    }
    while (i <= mid) {
        temp[k++] = v[i++];
    }
    while (j <= e) {
        temp[k++] = v[j++];
    }
    for (i = s, j = 0; i <= e; i++, j++) {
        v[i] = temp[j];
    }
    return count;
}
ll findInversions(vector<ll> &v, ll s, ll e) {
    if (s >= e) {
        return 0;
    }
    ll mid = s + (e-s)/2;
    ll x = findInversions(v, s, mid);
    ll y = findInversions(v, mid + 1, e);
    ll crossInversions = findCrossInv(v, s, e, mid);
    return x + y + crossInversions;
}
int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << findInversions(v, 0, n-1) << "\n";
    }
    return 0;
}