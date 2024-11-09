#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

constexpr int MAXN = 10000 + 10;
constexpr int trueX(int x) { return x << 1; }
constexpr int falseX(int x) { return (x << 1) | 1; }
constexpr int notX(int x) { return x ^ 1; }

int id = 0, dt[MAXN * 2];   // Discovery time for Tarjan's algorithm
bool finished[MAXN * 2];    // Tracks if a node's SCC is completed
vi adj[MAXN * 2];           // Adjacency list for implication graph
stack<int> s;               // Stack for Tarjan's algorithm
int sccId[MAXN * 2];        // SCC ID for each node
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

bool solve2SAT(int m) {
    for (int i = 2; i <= m * 2 + 1; ++i) {
        if (dt[i] == 0) dfs(i);
    }

    for (int i = 1; i <= m; ++i) {
        if (sccId[trueX(i)] == sccId[falseX(i)]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        int u = (x > 0 ? trueX(x) : falseX(-x));
        int v = (y > 0 ? trueX(y) : falseX(-y));

        adj[notX(u)].push_back(v); // ¬u → v
        adj[notX(v)].push_back(u); // ¬v → u
    }

    cout << (solve2SAT(m) ? "^_^\n" : "OTL\n");
    return 0;
}
