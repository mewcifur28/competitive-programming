/*
Consider an undirected graph consisting of 'n' nodes where each node is labeled from 1 to n and the edge between any two nodes is always of length 6 . We define node 's' to be the starting position for a BFS.

Given 'q' queries in the form of a graph and some starting node, 's' , perform each query by calculating the shortest distance from starting node 's' to all the other nodes in the graph. Then print a single line of n-1 space-separated integers listing node s's shortest distance to each of the n-1 other nodes (ordered sequentially by node number); if 's' is disconnected from a node, print -1 as the distance to that node.

Input Format
The first line contains an integer,q , denoting the number of queries. The subsequent lines describe each query in the following format:

Each line contains N and M, the number of nodes and edges respectively.

The next m lines contains u and v means that there is edge between u and v .

The last line contains 's', the starting node.

Constraints
1 <= q <= 10 2 <= n <= 1000 1 <= m <= (n*(n-1))/2 1 <= u,s,v <= n

Output Format
You have to print n-1 integer denoting the shortest distance from s to all other nodes excluding s itself.

Sample Input
2
4 2
1 2
1 3
1
3 1
2 3
2
Sample Output
6 6 -1
-1 6
*/
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph{
    map<T, list<T>> l;
public:
    void addEdge(T x, T y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void BFS(T start, int n) {
        queue<T> q;
        map<T, int> dist;
        //first initialise all the nodes w dist = INF
        for (auto nodePair: l) {
            auto node = nodePair.first;
            dist[node] = INT_MAX;
        }
        q.push(start);
        dist[start] = 0;
        while (!q.empty()) {
            //cout << q.front() << " ";
            //add neightbors of q.top() to the queue
            for (auto node: l[q.front()]) {
                if (dist[node] == INT_MAX) {
                    dist[node] = dist[q.front()] + 1;
                    q.push(node);
                }
            }
            q.pop();
        }
        for (int i = 1; i <= n; i++) {
            if (i == start) {
                continue;
            }
            if ((dist.find(i) == dist.end()) || dist[i] == INT_MAX) {
                cout << "-1 ";
            }
            else {
                cout << dist[i] * 6 << " ";
            }
        }
        cout << "\n";
    }
};
int main() {
    int q;
    cin >> q;
    while (q--) {
        Graph<int> g;
        int n, m;
        cin >> n >> m;
        while (m--) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }
        int s;
        cin >> s;
        g.BFS(s, n);
    }
    return 0;
}
