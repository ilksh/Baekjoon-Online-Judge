#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
typedef vector<int> vi;
typedef vector<vi> vvi;

int V; 
vvi capacity, flow;
vvi adj;

int solve(int source, int sink) {
    flow.assign(V, vi(V, 0));
    int totalFlow = 0;

    while (true) {
        queue<int> q;
        vi parent(V, -1);

        parent[source] = source;
        q.push(source);
        while (!q.empty() && parent[sink] == -1) {
            int from = q.front(); q.pop();
            for (auto to : adj[from]) {
                int r = capacity[from][to] - flow[from][to];
                if (r > 0 && parent[to] == -1) { 
                    parent[to] = from;
                    q.push(to);
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
        }
        totalFlow += curFlow;
    }
    return totalFlow;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        V = N; 

        capacity.assign(V, vi(V, 0)); 
        flow.assign(V, vi(V, 0));   
        adj.assign(V, vector<int>()); 

        for (int i = 0; i < M; ++i) {
            int x, y;
            cin >> x >> y;
            x--; y--; 
            capacity[x][y] = 1; 
            adj[x].push_back(y);
            adj[y].push_back(x); 
        }

        cout << solve(0, N - 1) << endl; 
    }
    return 0;
}
