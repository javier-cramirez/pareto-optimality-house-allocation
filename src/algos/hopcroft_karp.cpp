#include <vector>

using namespace std;

class HopKarp {

public:
    int n, m;
    vector<vector<int>> adj;
    vector<int> d, l, r;

    static const inf = 1e9;

    // given bipartite graph G=(L, R, E), matching M
    HopKarp(int n, int m) {
        adj.resize(n);
        d.resize(n);
        l.assign(n, -1);
        r.assign(n,-1);
    }    
    
    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }
    
    // find advancing edges 
    bool bfs() {
        queue<int> q;
            
        // initialize distances forall u in L
        for (int u=0; u<n; u++) {
            if (l[u] == -1) d[u] = 0; q.push(u);
            else d[u] = inf;
        }

        d[0] = inf;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                // v in R is unmatched, so set dist and enqueue
                if (d[r[v]] == inf) {
                    d[r[v]] = d[u] + 1;
                    q.push(r[v]);
                }
            }
        }

        return d[0] != inf;
    }

    bool dfs() {
        
    }

    int max_matching() {
        int matching = 0;

        while (bfs()) {
            // locate augmenting path for the free vertices in L
            // 
            for (int u = 0; u < n; u++) if (l[u] == -1 && dfs(u)) matching++;
        }
    
        return matching;
    }    

}
