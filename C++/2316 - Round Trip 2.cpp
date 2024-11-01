#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f;

vvi flow, capacity;
int n, p; // number of cities and routes

int solve(int source, int sink) {
    flow.assign(2 * n + 1, vi(2 * n + 1, 0));   
    int totalFlow = 0;

    while (true) {
        vi parent(2 * n + 1, -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;

        while (!q.empty() && parent[sink] == -1) {
            int from = q.front(); q.pop();

            for (int to = 1; to < 2 * n + 1; ++to) {
                int diff = capacity[from][to] - flow[from][to];

                if (diff <= 0 || parent[to] != -1) continue;

                q.push(to);
                parent[to] = from;

                if (to == sink) break;
            }
        }

        if (parent[sink] == -1) break; // no augmented path found

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

    cin >> n >> p;

    
    capacity.assign(2 * n + 1, vi(2 * n + 1, 0));

    // split one city in two nodes
    for (int i = 1; i <= n; ++i) {
        capacity[i][i + n] = 1; // i -> i + n 
    }

    for (int i = 0; i < p; ++i) {
        int from, to;
        cin >> from >> to;
        
        // To enable unrestricted use of connections between cities
        capacity[from + n][to] = INF;
        capacity[to + n][from] = INF;
    }

    cout << solve(1 + n, 2) << "\n"; 
    return 0;
}
