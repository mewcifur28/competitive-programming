/*
You are given an array A of N elements and Q queries. Each query consists of 3 integers L R K. For each query, you have to find the number of elements Ax1, Ax2,….,Axj>=K, where L<=x1, x2,…xj<=R.

Input Format
First line contains an integer N, denoting the number of elements in the array A. Next line contains N integers denoting the elements of the array. Next line contains a single integer Q, denoting the number of queries. Next Q lines contains Q queries, consisting of 3 integers each, L R K.

Constraints
1<=N,Q<=10^5
|Ai|, |K|<=10^9
1<=L, R<=N

Output Format
Print Q lines, where ith line contains the answer to the ith query.

Sample Input
5
1 2 3 4 5
5
1 4 1
1 5 2
1 5 3
1 5 4
1 5 5
Sample Output
4
4
3
2
1
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> mergeVector(vector<ll> &v1, vector<ll> &v2) {
    vector<ll> merged(v1.size()+v2.size());
    ll i = 0, j =0, k = 0;
    while (i < v1.size() && j < v2.size()) {
        merged[k++] = v1[i] < v2[j] ? v1[i++] : v2[j++];
    }
    while (i < v1.size()) {
        merged[k++] = v1[i++];
    }
    while (j < v2.size()) {
        merged[k++] = v2[j++];
    }
    return merged;
}
void makeTree(vector<vector<ll>> &tree, ll idx, ll *arr, ll s, ll e) {
    if (s == e) {
        tree[idx].push_back(arr[s]);
        return;
    }
    ll m = s + (e-s)/2;
    makeTree(tree, 2*idx, arr, s, m);
    makeTree(tree, 2*idx + 1, arr, m+1, e);
    tree[idx] = mergeVector(tree[2*idx], tree[2*idx + 1]);
    return;
}
ll makeQuery(vector<vector<ll>> &tree, ll idx, ll s, ll e, ll l, ll r, ll k) {
    if (l > e || s > r) {
        return 0;
    }
    if (s >= l && r >= e) {
        auto ki = lower_bound(tree[idx].begin(), tree[idx].end(), k);
        return ((tree[idx].size()) - (ki-tree[idx].begin()));
    }
    ll m = s + (e-s)/2;
    ll leftAns = makeQuery(tree, 2*idx, s, m, l, r, k);
    ll rightAns = makeQuery(tree, 2*idx + 1, m+1, e, l, r, k);
    return leftAns + rightAns;
}
int main() {
    ll n, q;
    cin >> n;
    ll *arr = new ll[n];
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<ll>> tree(4*n+1);
    makeTree(tree, 1, arr, 0, n-1);
    cin >> q;
    while (q--) {
        ll l, r, k;
        cin >> l >> r >> k;
        cout << makeQuery(tree, 1, 0, n-1, l-1, r-1, k) << "\n";
    }
    return 0;
}
