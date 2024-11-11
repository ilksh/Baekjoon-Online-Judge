#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

constexpr int MAX = 20000 + 10;
constexpr int trueX(int x) { return x << 1; }
constexpr int falseX(int x) { return (x << 1) | 1; }
constexpr int notX(int x) { return x ^ 1; }

int id = 0, dt[MAX];    // Discovery time for nodes
bool finished[MAX];     // Tracks if a node's SCC is completed
vi adj[MAX];            // Adjacency list for implication graph
vvi SCCs;               // Stores lists of SCCs
stack<int> s;           // Stack used in DFS
int sccId[MAX];         // SCC ID for each node

// DFS function to find SCCs using `parent` logic
int dfs(int x) {
    dt[x] = ++id;       // Assign a unique discovery time
    s.push(x);          // Push current node onto the stack

    int parent = dt[x]; // Initially, the node is its own parent
    for (int nextNode : adj[x]) {
        if (dt[nextNode] == 0) {
            // If nextNode is unvisited, recurse
            parent = min(parent, dfs(nextNode));
        } else if (!finished[nextNode]) {
            // If nextNode is in the current DFS path, update parent
            parent = min(parent, dt[nextNode]);
        }
    }

    // If `x` is the root of an SCC
    if (parent == dt[x]) {
        vi scc;
        while (true) {
            int t = s.top(); s.pop();
            scc.push_back(t);
            finished[t] = true;
            sccId[t] = SCCs.size(); // Assign SCC ID
            if (t == x) break;     // Stop when SCC is fully traversed
        }
        SCCs.push_back(scc); // Save the SCC
    }

    return parent; // Return the updated parent
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; // Number of variables and clauses
    cin >> n >> m;

    // Build the implication graph
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        u = (u > 0 ? trueX(u) : falseX(-u));
        v = (v > 0 ? trueX(v) : falseX(-v));

        adj[notX(u)].push_back(v); // ¬u → v
        adj[notX(v)].push_back(u); // ¬v → u
    }

    // Find SCCs using Tarjan's algorithm 
    for (int i = 2; i <= n * 2 + 1; ++i) {
        if (dt[i] == 0) dfs(i);
    }

    // Check for satisfiability
    for (int i = 1; i < n + 1; ++i) {
        if (sccId[trueX(i)] == sccId[falseX(i)]) {
            cout << "0\n"; // UNSATISFIABLE
            return 0;
        }
    }

    cout << "1\n"; // SATISFIABLE
    return 0;
}
