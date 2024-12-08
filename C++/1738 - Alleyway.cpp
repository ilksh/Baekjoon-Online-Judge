#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 101; 
const int INF = INT_MAX; 

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

int n, m; 
vpii adj[MAX_V];
vi rev[MAX_V]; 
int dist[MAX_V], pre[MAX_V], vis[MAX_V];
bool hasCycle = false; 


void bellmanFord(int start) {
    fill(dist, dist + MAX_V, INF); 
    fill(pre, pre + MAX_V, -1); 
    dist[start] = 0; 

    // Relax edges n times to find the shortest paths
    for (int iter = 1; iter <= n; ++iter) {
        for (int cur = 1; cur <= n; ++cur) {

            if (dist[cur] == INF) continue; // Skip unreachable nodes

            for (auto &edge : adj[cur]) {
                int next = edge.first, cost = edge.second;
                if (dist[next] > dist[cur] + cost) {
                    dist[next] = dist[cur] + cost; 
                    pre[next] = cur; 
              
                    if (iter == n && vis[next]) hasCycle = true;
                }
            }
        }
    }
}

void markReachableFrom(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : rev[cur]) {
            if (!vis[next]) {
                vis[next] = 1; 
                q.push(next);
            }
        }
    }
}

void printPath(int target) {
    vi path;
    for (int cur = target; cur != -1; cur = pre[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end()); 
    for (int node : path) cout << node << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, -w); 
        rev[v].push_back(u);      
    }

    markReachableFrom(n); 
    bellmanFord(1);      

    if (hasCycle) cout << -1 << "\n"; 

    else printPath(n);

    return 0;
}
