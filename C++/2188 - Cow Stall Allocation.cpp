#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f;

int V; // max number of nodes: N + M + source + sink

vvi capacity;
vvi flow;
vvi adj;

int solve(int source, int sink) {
    flow.assign(V, vi(V, 0));  
    int totalFlow = 0;

    while(true) {    
        vi parent(V, -1);
        parent[source] = source;

        queue<int> q;
        q.push(source);

        while(!q.empty() && parent[sink] == -1) { // bfs: find augmented path
            auto from = q.front(); q.pop();

            for (auto to : adj[from]) {
                int r = capacity[from][to] - flow[from][to];
                if (r <= 0) continue;
                if (parent[to] != -1) continue;
                q.push(to);
                parent[to] = from;
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
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; // number of cow
    int M; // number of stall

    cin >> N >> M;

    // source <-> cow <-> stall <-> sink
    V = N + M + 2;          
    int source = 0;
    int sink = N + M + 1;

    capacity.assign(V, vi(V, 0));
    adj.assign(V, vi());
    
    for (int i = 1; i < N + 1; ++i) {
        // source <-> cow
        adj[source].push_back(i);
        adj[i].push_back(source);
        capacity[source][i] = 1;

        int Z; 
        cin >> Z;
        while(Z--) {
            int S; // Preferred Stall
            cin >> S;

            // cow <-> stall
            adj[i].push_back(N + S);       
            adj[N + S].push_back(i);      
            capacity[i][N + S] = 1;        
        }
    }

    // stall <-> sink
    for (int i = 1; i < M + 1; ++i) {
        adj[N + i].push_back(sink);
        adj[sink].push_back(N + i);
        capacity[N + i][sink] = 1;
    }

    cout << solve(source, sink) << "\n";

    return 0;
}
