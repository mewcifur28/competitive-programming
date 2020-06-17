// https://www.hackerrank.com/challenges/journey-to-the-moon/problem

#include <bits/stdc++.h>
#define int long long int
using namespace std;

vector<string> split_string(string);

class Graph{
    map<int, list<int>> l;
public:
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    //returns number of nodes in component
    int DFS_helper(int src, map<int, bool> &visited) {
        visited[src] = true;
        int ans = 1;
        for (auto nbr: l[src]) {
            if (!visited[nbr]) {
                ans += DFS_helper(nbr, visited);
            }
        }
        return ans;
    }
    //returns a vector containing number of astronauts in each country
    vector<int> DFS() {
        vector<int> countries;
        map<int, bool> visited;
        for(auto nodePair: l) {
            auto node = nodePair.first;
            visited[node] = false;
        }
        for(auto nodePair: l) {
            auto node = nodePair.first;
            if (!visited[node]) {
                int numOfAstr = DFS_helper(node, visited);
                countries.push_back(numOfAstr);
            }
        }
        return countries;
    }
};

// Complete the journeyToMoon function below.
int journeyToMoon(int n, vector<vector<int>> astronauts) {

    Graph g;
    //nodes should be from 0 to n-1
    //add all nodes to the graph
    for (int i = 0; i < astronauts.size(); i++) {
        g.addEdge(astronauts[i][0], astronauts[i][1]);
    }
    vector<int> countries = g.DFS();
    int ans = ((n)*(n-1))/2;
    for (int i = 0; i < countries.size(); i++) {
        int astro = countries[i];
        ans -= (((astro)*(astro-1))/2);
    }
    return ans;
}

signed main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
