/*
You are given an array A of n elements and Q queries. Each query can be of following types:

1 L R: Print the minimum value in AL, AL+1, AL+2….,AR.
2 X Y: Update the value of Ax with Y.
Input Format
First line contains integers N and Q, denoting the number of elements and number of queries. Next line contains N integers, denoting A1, A2, A3….,AN. Next Q lines contains Q queries.

Constraints
1<=N,Q<=10^5 |Ai|,|Y|<=10^9 1<=L,R,X<=N

Output Format
Answer each query of type 1.

Sample Input
5 5
1 4 3 5 2
1 1 5
2 3 9
1 2 4
1 2 5
1 3 4
Sample Output
1
4
2
5
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void buildTree(ll *a, ll s, ll e, ll *tree, ll index) {
    if (s == e) {
        tree[index] = a[s];
        return;
    }
    ll mid = s + (e-s)/2;
    buildTree(a, s, mid, tree, 2*index);
    buildTree(a, mid+1, e, tree, 2*index + 1);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
}
void updateNode(ll *a, ll s, ll e, ll *tree, ll index, ll i, ll val) {
    if (i < s || i > e) {
        return;
    }
    if (s == e) {
        //a[i] = val;
        tree[index] = val;
        return;
    }
    ll mid = s + (e-s)/2;
    updateNode(a, s, mid, tree, 2*index, i, val);
    updateNode(a, mid+1, e, tree, 2*index + 1, i, val);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
}
ll minQuery(ll *a, ll s, ll e, ll *tree, ll index, ll l, ll r) {
    if (l <= s && e <= r) {
        return tree[index];
    }
    if (s > r || e < l) {
        return LLONG_MAX;
    }
    ll mid = s + (e-s)/2;
    ll left = minQuery(a, s, mid, tree, 2*index, l, r);
    ll right = minQuery(a, mid+1, e, tree, 2*index+1, l, r);
    return min(left, right);
}
int main() {
    ll N, Q;
    cin >> N >> Q;
    ll *A = new ll[N], *tree = new ll[4*N + 1];
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    buildTree(A, 0, N-1, tree, 1);
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll l, r;
            cin >> l >> r;
            cout << minQuery(A, 0, N-1, tree, 1, l-1, r-1) << "\n";
        }
        else {
            ll x, y;
            cin >> x >> y;
            updateNode(A, 0, N-1, tree, 1, x-1, y);
        }
    }
    return 0;
}