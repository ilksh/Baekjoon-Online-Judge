#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int MAX = 2005;
const int INF = 1e9;

vvi capacity, flow, cost;
vvi adj(MAX);

void addEdge(int u, int v, int cap, int w) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v] = cap;
    cost[u][v] = w;
    cost[v][u] = -w;
}

int mcmf(int source, int sink) {
    int totalCost = 0;

    while (true) {
        vi parent(MAX, -1);
        vi dist(MAX, INF);
        queue<int> q;
        vector<bool> inQueue(MAX, false);

        dist[source] = 0;
        q.push(source);
        inQueue[source] = true;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            inQueue[cur] = false;

            for (int next : adj[cur]) {
                int r = capacity[cur][next] - flow[cur][next];
                int nextCost = dist[cur] + cost[cur][next];

                if (r <= 0 || nextCost >= dist[next]) continue;

                dist[next] = nextCost;
                parent[next] = cur;

                if (!inQueue[next]) {
                    q.push(next);
                    inQueue[next] = true;
                }
            }
        }

        if (parent[sink] == -1) break;

        int curFlow = INF;
        for (int p = sink; p != source; p = parent[p]) {
            int par = parent[p];
            int r = capacity[par][p] - flow[par][p];
            curFlow = min(curFlow, r);
        }

        for (int p = sink; p != source; p = parent[p]) {
            int par = parent[p];
            flow[par][p] += curFlow;
            flow[p][par] -= curFlow;
            totalCost += curFlow * cost[par][p];
        }
    }

    return totalCost;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        capacity.assign(MAX, vi(MAX, 0));
        flow.assign(MAX, vi(MAX, 0));
        cost.assign(MAX, vi(MAX, INF));
        for (int i = 0; i < MAX; ++i) adj[i].clear();

        int source = 2 * n + 2;
        int sink = 2 * n + 3;

        // Source to the first node group
        addEdge(source, 1 * 2, 2, 0);

        // Sink connection to the last node group
        addEdge(n * 2, sink, 2, 0);

        // Split each node into in-node and out-node
        for (int i = 1; i <= n; ++i) {
            addEdge(i * 2, i * 2 + 1, (i == 1 || i == n) ? 2 : 1, 0);
        }

        // Add connections between nodes
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            addEdge(u * 2 + 1, v * 2, 1, w);
        }

        auto result = mcmf(source, sink);
        cout << result << "\n";
    }

    return 0;
}
