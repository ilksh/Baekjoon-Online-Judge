#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef queue<int> qi;

const int MAX_V = 26 * 2 + 1;
const int INF = 1e9;

int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
int V = MAX_V;

int networkFlow(int source, int sink) {
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;

    while (true) {
        vi parent(V, -1);
        qi q;

        parent[source] = source;
        q.push(source);
        
        // find the augmented path using bfs
        while (!q.empty() && parent[sink] == -1) {
            int cur = q.front(); q.pop();

            for (int next = 0; next < V; ++next) {
                int diff = capacity[cur][next] - flow[cur][next];
                if (diff <= 0 || parent[next] != -1) continue;
            
                q.push(next);
                parent[next] = cur;
            }
        }

        if (parent[sink] == -1) break;

        int amount = INF;

        for (int p = sink; p != source; p = parent[p]) {
            int par = parent[p];
            amount = min(amount, capacity[par][p] - flow[par][p]);
        }

        for (int p = sink; p != source; p = parent[p]) {
            int par = parent[p];
            flow[par][p] += amount;
            flow[p][par] -= amount;
        }

        totalFlow += amount;
    }
    return totalFlow;
}

int convert (char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A' + 1;
    else if (c >= 'a' && c <= 'z') return c - 'a' + 1 + 26;
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(capacity, 0, sizeof(capacity));

    int e;
    cin >> e;

    for (int i = 0; i < e; ++i) {
        char c1, c2;
        int w;
        cin >> c1 >> c2 >> w;
        int from = convert(c1);
        int to = convert(c2);

        capacity[from][to] += w;
        capacity[to][from] += w;
    }
    
    int source = convert('A'); 
    int sink = convert('Z');  
    cout << networkFlow(source, sink) << "\n";

    return 0;
}