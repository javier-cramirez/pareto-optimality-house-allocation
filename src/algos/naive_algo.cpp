#include <iostream>
#include <vector>

using namespace std;

bool dfs (int u, const vector<vector<int>> &adj, vector<int> &match, vector<bool> &visited) {
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            
            // check if vertex v has no match, or if its match has another path
            if (match[v] == -1 || dfs(match[v], adj, match, visited)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int naiveMatching(int n, int m, const vector<vector<int>> &adj) {
    vector<int> match(m, -1);

    int res = 0;

    for (int u = 0; u < n; u++) {
        vector<bool> visited(m, false);
        if (dfs(u, adj, match, visited)) 
            res++;
    }
    return res;
}

int main() {
    vector<vector<int>> adj = {
        {0, 1},    // U0 is adjacent to V0, V1
        {1, 2},    // U1 is adjacent to V1, V2
        {2, 3},    // U2 is adjacent to V2, V3
        {0, 3}     // U3 is adjacent to V0, V3
    };
    
    int n = 4; // Size of U.
    int m = 4; // Size of V.
    
    int maxMatching = naiveMatching(n, m, adj);
    cout << "Maximum matching size: " << maxMatching << endl;
    
    return 0;
}
