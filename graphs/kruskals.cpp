/*
Given an undirected weighted graph with V nodes and E edges , find the weight of the minimum spanning tree. The IDs of the nodes are between 0 and n-1 inclusive.


Note : Try using both Kruskal and Prim's Algorithm for this problem

Input Format
First line contains two integers V and E.
Next E lines contain three space separated integers - u ,v and w
u and v are the nodes , w = weight of edge

Constraints
1 <= V <= 10000
1 <= E <= 100000
0 <= Weight of each edge <= 10000

Output Format
Display a single integer denoting the total weight of the minimum spanning tree.

Sample Input
4 5
0 1 10
1 2 15
0 2 5
3 1 2
3 2 40
Sample Output
17
Explanation
The edge between 2 & 3 with weight=15 and the edge between 3 & 4 with weight = 40 will not be a part of the final MST. The total weight of the remaining edges is 17.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct dsu{
    ll *par;
    void init(ll n) {
        par = new ll[n];
        for (ll i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    ll getSP(ll x) {
        return (x == par[x]) ? x : getSP(par[x]);
    }
    bool unite(ll x, ll y) {
        ll sx = getSP(x), sy = getSP(y);
        if (sx != sy) {
            par[sx] = par[sy];
            return true;
        }
        return false;
    }
};
int main() {
    ll V, E, u, v, w;
    cin >> V >> E;
    multimap<ll, pair<ll, ll>> edges;
    for (ll i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edges.insert({w, {u, v}});
    }
    // cout << E << "\n";
    dsu g;
    g.init(V);
    ll minWt = 0;
    for (auto e: edges) {
        ll wt = e.first;
        ll n1 = e.second.first;
        ll n2 = e.second.second;
        // cout << n1 << " " << n2 << " " << wt << "\n";
        if (g.unite(n1, n2)) {
            // cout << n1 << " " << n2 << " " << wt << "\n";
            minWt += wt;
        }
    }
    cout << minWt;
    return 0;
}
