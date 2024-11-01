#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f;

vvi flow;
vvi capacity;
int n, p; // number of city and route

int solve(int source, int sink) {
    flow.assign(n + 1, vi(n + 1, 0));   
    int totalFlow = 0;

    while(true) {
        vi parent(n + 1, -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;

        while(!q.empty() && parent[sink] == -1) {
            auto from = q.front(); q.pop(); 
            for (int to = 1; to < n + 1; ++to) {
                int diff = capacity[from][to] - flow[from][to];
                if (diff <= 0 || parent[to] != -1) continue;
                q.push(to);
                parent[to] = from;
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

    capacity.assign(n + 1, vi(n + 1, 0));

    for (int i = 0; i < p; ++i) {
        int from, to;
        cin >> from >> to;
        capacity[from][to] = 1;
    }

    cout << solve(1, 2) << "\n";
    return 0;
}