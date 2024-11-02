#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_N = 100001;

typedef pair<int, int> pii;
typedef pair<int, pii> ipii;

int totalWeight;
vector<pii> adj[MAX_N];
int dist[MAX_N];

void dijkstra(int start) {
    priority_queue<ipii> pq;
    pq.push({0, {start, 0}});
    dist[start] = 0;

    while (!pq.empty()) {
        auto cur = pq.top();pq.pop();

        int curCost = -cur.first;
        int curNode = cur.second.first;
        int maxEdge = cur.second.second;

        if (dist[curNode] < curCost) continue;

        for (auto &[nextNode, nextCost] : adj[curNode]) {
            int newCost = curCost + maxEdge + nextCost - max(maxEdge, nextCost);
            if (dist[nextNode] > newCost) {
                dist[nextNode] = newCost;
                pq.push({-newCost, {nextNode, max(maxEdge, nextCost)}});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        totalWeight += w;
    }

    fill(dist, dist + MAX_N, INF);

    int s, t;
    cin >> s >> t;
    dijkstra(s);

    cout << totalWeight - dist[t] << '\n';
    return 0;
}
