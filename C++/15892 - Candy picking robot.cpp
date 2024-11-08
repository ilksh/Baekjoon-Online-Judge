#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef queue<int> qi;

const int MAX_V = 302;
const int INF = 0x3f3f3f3f;

int V;
int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

int edmondsKarp(int source, int sink) {
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;

    while (true) { 
        vi parent(MAX_V, -1);
        qi q;
        parent[source] = source;
        q.push(source);

        while (!q.empty() && parent[sink] == -1) {
            int here = q.front(); q.pop();
            for (int there = 1; there <= V; ++there) {
                if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
                    parent[there] = here;
                    q.push(there);
                    if (there == sink) break;
                }
            }
        }

        if (parent[sink] == -1) break; 

        int amount = INF;
        for (int p = sink; p != source; p = parent[p]) {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }

        for (int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }

        totalFlow += amount;
    }
    return totalFlow;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    V = n; 

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        capacity[u][v] += c; 
        capacity[v][u] += c; 
    }

    cout << edmondsKarp(1, n) << "\n";
    return 0;
}
