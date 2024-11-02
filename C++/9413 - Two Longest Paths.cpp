#include <bits/stdc++.h>

using namespace std;

const int MAX = 605;
const int INF = 1e9;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

vvi capacity, flow, cost;
vector<vi> adj(MAX);

void addEdge(int from, int to, int cap, int w) {
    adj[from].push_back(to);
    adj[to].push_back(from);
    capacity[from][to] = cap;
    cost[from][to] = w;
    cost[to][from] = -w;
}

int mcmf(int source, int sink) {
    int totalCost = 0;

    while (true) {
        vi parent(MAX, -1);
        vi dist(MAX, INF);
        vector<bool> inQueue(MAX, false);
        queue<int> q;

        dist[source] = 0;
        q.push(source);
        inQueue[source] = true;

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            inQueue[cur] = false;

            for (int next : adj[cur]) {
                int r = capacity[cur][next] - flow[cur][next];
                int nextCost = dist[cur] + cost[cur][next];
                if (r <= 0 || nextCost >= dist[next]) continue;
            
                dist[next] = dist[cur] + cost[cur][next];
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
    cin.tie(nullptr); cout.tie(nullptr);

    int T, n, m;
    cin >> T;

    while (T--) {
        capacity.assign(MAX, vi(MAX, 0));
        flow.assign(MAX, vi(MAX, 0));
        cost.assign(MAX, vi(MAX, INF));
        for (int i = 0; i < MAX; ++i) adj[i].clear();

        cin >> n >> m;
        int start = 2 * n + 1, source = 2 * n + 2, sink = 2 * n + 3;

        addEdge(source, start, 2, 0);

        for (int i = 1; i < n + 1; ++i) {
            addEdge(start, i, 1, 0);
            addEdge(i, i + n, 1, -1);
            addEdge(i + n, sink, 1, 0);
        }

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            addEdge(u + n, v, 1, 0);
        }

        auto rst = mcmf(source, sink);

        cout << -rst << "\n";
    }
    return 0;
}
