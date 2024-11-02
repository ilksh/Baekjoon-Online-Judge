#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int INF =  0x3f3f3f3f;

vvi capacity, flow, cost;
vvi adj;

int V;

void makeLink(int u, int v, int cap) {
    // non directed graph
    adj[u].push_back(v);
    adj[v].push_back(u);
    cost[u][v] = cap;
    cost[v][u] = cap;
    capacity[u][v] = cap;
    capacity[v][u] = cap;
}

int mcmf(int source, int sink) {
    flow.assign(V, vi(V, 0));
    int totalFlow = 0;
    int totalCost = 0;

    while (true) {
        vi dist(V, INF);
        vi parent(V, -1);

        vector<bool> isInQ(V, false);
        queue<int> q;
        
        dist[source] = 0;
        parent[source] = source;
        isInQ[source] = true;
        q.push(source);

        while(!q.empty()) {
            auto from = q.front(); q.pop();
            isInQ[from] = true;

            for (auto to : adj[from]) {
                int r = capacity[from][to] - flow[from][to]; 
                int newCost = dist[from] + cost[from][to];

                if (r <= 0 || dist[to] <= newCost) continue;

                dist[to] = newCost;
                parent[to] = from;
                if (!isInQ[to]) q.push(to);
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
            totalCost += cost[par][p];
        }
        totalFlow += curFlow;
    }
    return totalFlow;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; // number of node and edge
    cin >> n >> m;  
    V = n + 1;

    capacity.assign(V, vi(V, 0));
    cost.assign(V, vi(V, 0));
    adj.assign(V, vi());

    for (int i = 0; i < m; ++i) {
        int u, v, cap;
        cin >> u >> v >> cap;
        makeLink(u, v, cap);
    }
    int source, sink;
    cin >> source >> sink;

    cout << mcmf(source, sink) << "\n";
    return 0;
}