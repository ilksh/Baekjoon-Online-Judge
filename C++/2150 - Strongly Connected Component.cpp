#include<bits/stdc++.h>

using namespace std;

const int MAX_V = 1e4 + 4;
const int MAX_E = 1e5 + 5;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int id, dt[MAX_V]; // dt stores discovery times
bool finished[MAX_V]; // Tracks if a node's DFS is complete

vi adj[MAX_E], adj_rev[MAX_E]; // Adjacency list for storing graph edges and reversed edges
vvi SCCs; // Stores lists of SCCs
stack<int> s; // Stack used in DFS

void dfs(int x) {
    dt[x] = 1; // Mark as visited
    for (auto nextNode : adj[x]) {
        if (!dt[nextNode]) dfs(nextNode);
    }
    s.push(x); // Push current node to stack after visiting all reachable nodes
}

void dfs_reverse(int x, vi& scc) {
    scc.push_back(x); // Add to current SCC
    finished[x] = true; // Mark as finished
    for (int nextNode : adj_rev[x]) {
        if (!finished[nextNode]) dfs_reverse(nextNode, scc);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj_rev[to].push_back(from); // Reverse the edge
    }

    // First pass: Fill stack with vertices in finishing order
    for (int i = 1; i <= v; ++i) {
        if (!dt[i]) dfs(i);
    }

    // Second pass: Process reversed graph in order of finishing times
    while (!s.empty()) {
        int x = s.top(); s.pop();
        if (!finished[x]) {
            vi scc;
            dfs_reverse(x, scc);
            sort(scc.begin(), scc.end()); // Sort vertices in ascending order
            SCCs.push_back(scc);
        }
    }

    // Sort SCCs based on the smallest vertex in each SCC
    sort(SCCs.begin(), SCCs.end(), [](const vi& a, const vi& b) { return a[0] < b[0]; });

    cout << SCCs.size() << "\n";
    for (const auto& scc : SCCs) {
        for (int vertex : scc) cout << vertex << " ";
        cout << "-1\n";
    }
    return 0;
}
