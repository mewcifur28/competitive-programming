/*
There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

Input Format
The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.

Constraints
1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

Output Format
An integer that denotes the number of permissible ways to choose a pair of cities.

Sample Input
5 3
0 1
2 3
0 4
Sample Output
6
Explanation
0 1 4 cannot be reached by 2 hence (2,0) (2,1) (2,4) and also 0 1 4 cannot be reached by 3 so (3,0) (3,1) (3,4) hence 6 ways.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Graph{
    public:
    map<ll, list<ll>> adjList;
    vector<int> vis;
    Graph(ll n) {
        vis.reserve(n);
        for (int i = 0; i < n; i++) {
            vis[i] = false;
        }
    }
    void insertEdge(ll x, ll y) {
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    ll dfs(ll src) {
        vis[src] = true;
        ll cnt = 0;
        for (auto nbr: adjList[src]) {
            if (!vis[nbr]) {
                cnt += dfs(nbr);
            }
        }
        return cnt+1;
    }
};
int main() {
    ll n, m;
    cin >> n >> m;
    Graph g(n);
    while (m--) {
        ll x, y;
        cin >> x >> y;
        g.insertEdge(x, y);
    }
    vector<ll> components;
    for (int i = 0; i < n; i++) {
        if (!g.vis[i]){
            ll val = g.dfs(i);
            components.push_back(val);
        }
    }
    ll ans = 0;
    for (int i = 0; i < components.size(); i++) {
        for (int j = i+1; j < components.size(); j++) {
            ans += components[i]*components[j];
        }
    }
    cout << ans;
    return 0;
}
