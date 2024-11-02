#include<bits/stdc++.h>


using namespace std;

typedef pair<int, int> pii;

const int INF = 2 * (1e9);
const int MAX_N = 310;

int tc, n, m;
int capacity[MAX_N][MAX_N], flow[MAX_N][MAX_N];
vector<pii> adj[MAX_N];

void maxFlow(int source, int sink) {
    while (true) {
        int parent[MAX_N];
        memset(parent, -1, sizeof(parent));
        
        queue<int> q;
        q.push(source);
        
        while (!q.empty() && parent[sink] == -1) {
            auto cur = q.front(); q.pop();
            
            for (auto& e : adj[cur]) {
                auto next = e.first;
                int r = capacity[cur][next] - flow[cur][next];
                if (r <= 0 || parent[next] != -1) continue;

                parent[next] = cur;
                q.push(next);
                if (next == sink) break;   
            }
        }
        
        if (parent[sink] == -1) break;

        int curFlow = INF;

        for (int p = sink; p != source; p = parent[p]) {
            int par = parent[p];
            int r =  capacity[par][p] - flow[par][p];
            curFlow = min(curFlow, r);
        }
        
        for (int p = sink; p != source; p = parent[p]) {
            int par= parent[p];
            flow[par][p] += curFlow;
            flow[p][par] -= curFlow;
        }
    }
}

void solve() {
    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));
    for (int i = 0; i < MAX_N; ++i) adj[i].clear();
    
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) { // input
        int from, to, cap;
        cin >> from >> to >> cap;
        
        adj[from].push_back({to, cap});
        adj[to].push_back({from, 0});
        capacity[from][to] += cap;
    }
    
    maxFlow(1, n);
    
    int cnt = 0;
    for (int i = 1; i < n + 1; ++i) {
        for (auto& edge : adj[i]) {
            int j = edge.first;
            if (edge.second == 0 || capacity[i][j] != flow[i][j]) continue;
            
            int parent[MAX_N];
            memset(parent, -1, sizeof(parent));
            
            queue<int> q;
            q.push(i);
            while (!q.empty() && parent[j] == -1) {
                auto cur = q.front(); q.pop();
                
                for (auto& e : adj[cur]) {
                    int next = e.first;
                    if (cur == i && next == j) continue;
                    int r = capacity[cur][next] - flow[cur][next];
                    if (r <= 0 || parent[next] != -1) continue;
              
                    parent[next] = cur;
                    q.push(next);
                    if (next == j) break;   
                }
            }
            
            if (parent[j] == -1) cnt++;
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tc;
    while (tc--) solve();
    
    return 0;
}
