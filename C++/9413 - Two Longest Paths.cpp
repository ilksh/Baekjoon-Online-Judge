#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;


const int MAX = 605;
const int INF = 1e9;

vvi capacity, flow, cost;
vvi adj(MAX);
int V = MAX;

void addEdge(int u, int v, int cap, int w) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v] = cap;
    cost[u][v] = w;
    cost[v][u] = -w;
}

int mcmf (int source, int sink) {
    int totalCost = 0;

    while(true) {
        vi parent(MAX, -1);
        vi dist(MAX, INF);
        queue<int> q;
        vector<bool> inQueue(MAX, false);
    
        dist[source] = 0;
        q.push(source);
        inQueue[source] = true;

        while(!q.empty()) { // find the augmenting path
            auto cur = q.front(); q.pop();
            inQueue[cur] = false;

            for (int next : adj[cur]) {
                int r = capacity[cur][next] - flow[cur][next];
                int nextCost = dist[cur] + cost[cur][next];

                // unable to send flow or not a shortest path
                if (r <= 0 || nextCost >= dist[next]) continue;

                dist[next] = nextCost;
                parent[next] = cur;

                if (!inQueue[next]) {
                    q.push(next);
                    inQueue[next] = true;
                }
            }
        }

        // no augmenting path found
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

    int TC;
    cin >> TC;
    
    while(TC--) {
        int n, m; // # of node and edge
        cin >> n >> m;
        // V = 2 * n + 4;

        capacity.assign(MAX, vi(MAX, 0));
        flow.assign(MAX, vi(MAX, 0));
        cost.assign(MAX, vi(MAX, INF));
        for (int i = 0; i < MAX; ++i) adj[i].clear();

        int start = 2 * n + 1;
        int source = 2 * n + 2;
        int sink = 2 * n + 3;

        // source-start and set capacity as 2 bc 
        // There are two groups of tourists planning to visit the city
        addEdge(source, start, 2, 0);

        for (int i = 1; i < n + 1; ++i) {
            // start - node i
            addEdge(start, i, 1, 0);
            // in_node - out_node
            addEdge(i, i + n, 1, -1);
            // out_node - sink
            addEdge(i + n, sink, 1, 0);
        }

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            // connect node u - node v
            addEdge(u + n, v, 1, 0);
        }

        auto rst = mcmf(source, sink);

        cout << -rst << "\n";
    }
    return 0;
}