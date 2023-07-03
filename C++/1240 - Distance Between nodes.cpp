#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii; // {node, weight}

const int MAX_N = 1e3 + 3;
vector<pii> adj[MAX_N];

int solve(int node1, int node2) {
    int rst = 0;
    queue<int> q;
    q.push(node1);
    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        int nextNode = adj[cur][0].first;
        int nextWeight = adj[cur][0].second;
        rst += nextWeight;
        if (nextNode != node2) {
            q.push(nextNode);
        }
    }
    return rst;    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    for (int i = 0 ; i < n - 1 ; ++i) {
        int u, v, w; // u, v: node | w: weight of edge
        cin >> u >> v >> w;
        adj[u].push_back({v ,m});
        adj[v].push_back({u ,m});
    }

    for (int j = 0 ; j < m; ++j) {
        int node1, node2;
        cin >> node1 >> node2;
        cout << solve(node1, node2) << "\n";
    }

    return 0;
}