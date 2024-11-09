#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

constexpr int MAXN = 2000 + 10;
constexpr int MAXL = 1000000 + 10;

constexpr int trueX(int x) { return x << 1; }
constexpr int falseX(int x) { return (x << 1) | 1; }
constexpr int notX(int x) { return x ^ 1; }

int id = 0, dt[MAXL * 2];   // Discovery time for Tarjan's algorithm
bool finished[MAXL * 2];    // Tracks if a node's SCC is completed
vi adj[MAXL * 2];           // Adjacency list for implication graph
stack<int> s;               // Stack for Tarjan's algorithm
int sccId[MAXL * 2];        // SCC ID for each node
vvi SCCs;                   // Stores SCCs

int dfs(int x) {
    dt[x] = ++id;
    s.push(x);
    int parent = dt[x];
    for (int nextNode : adj[x]) {
        if (dt[nextNode] == 0) {
            parent = min(parent, dfs(nextNode));
        } else if (!finished[nextNode]) {
            parent = min(parent, dt[nextNode]);
        }
    }

    if (parent == dt[x]) {
        vi scc;
        while (true) {
            int t = s.top(); s.pop();
            scc.push_back(t);
            finished[t] = true;
            sccId[t] = SCCs.size();
            if (t == x) break;
        }
        SCCs.push_back(scc);
    }

    return parent;
}

bool solve2SAT(int n) {
    for (int i = 2; i <= n * 2 + 1; ++i) {
        if (dt[i] == 0) dfs(i);
    }

    for (int i = 1; i <= n; ++i) {
        if (sccId[trueX(i)] == sccId[falseX(i)]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;

    while (cin >> n >> m) {
        id = 0;
        memset(dt, 0, sizeof(dt));
        memset(finished, 0, sizeof(finished));
        memset(sccId, 0, sizeof(sccId));
        SCCs.clear();
        
        for (int i = 0; i < MAXL * 2; ++i) adj[i].clear();

        for (int i = 0; i < m; ++i) {
            int u, v;
            char c1, c2;
            cin >> c1 >> u >> c2 >> v;

            u = (c1 == '+' ? trueX(u) : falseX(u));
            v = (c2 == '+' ? trueX(v) : falseX(v));

            adj[notX(u)].push_back(v); // ¬u → v
            adj[notX(v)].push_back(u); // ¬v → u
        }

        cout << (solve2SAT(n) ? "1\n" : "0\n");
    }

    return 0;
}
