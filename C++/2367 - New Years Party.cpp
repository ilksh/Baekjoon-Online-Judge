#include<bits/stdc++.h>

using namespace std;

typedef queue<int> qi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f;

int V; // number of cow + food + source + sink

vvi capacity;
vvi flow;
vvi adj; // adjacent list

int solve(int source, int sink) {
    flow.assign(V, vi(V, 0));
    int totalFlow = 0;

    while(true) {
        vi parent(V, -1);
        qi q;
        
        parent[source] = source;
        q.push(source);

        while(!q.empty() && parent[sink] == -1) { // find the augmented path
            int from = q.front(); q.pop();

            for (int to : adj[from]) {
                int remain = capacity[from][to] - flow[from][to];
                if (remain <= 0) continue;
                if (parent[to] != -1) continue;

                q.push(to);
                parent[to] = from;
            }
        }

        // no augmented path found
        if (parent[sink] == -1) break;

        int curFlow = INF;
        
        for(int p = sink; p != source; p = parent[p]) {
            int par = parent[p];
            int r = capacity[par][p] - flow[par][p];
            curFlow = min(curFlow, r);
        }

        for(int p = sink; p != source; p = parent[p]) {
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
    int D; // different kinds of food
    int K; // Each cow can bring K dishes 

    cin >> N >> K >> D;

    // 1 ~ N: Cow
    // N + 1 ~ N + D + 2: Food
    V = N + D + 2; 
    int source = 0;
    int sink = N + D + 1;

    capacity.assign(V, vi(V, 0));
    adj.assign(V, vi());

    // the limit on total number of each of the various dishes 
    // that can be brought to the party
    for (int i = 1; i < D + 1; ++i) {
        int foodLimit; 
        cin >> foodLimit;
        capacity[N + i][sink] = foodLimit;

        // food <-> sink
        adj[N + i].push_back(sink);
        adj[sink].push_back(N + i);
    }

    for (int i = 1; i < N + 1; ++i) {
        capacity[source][i] = K;

        // source <-> cow
        adj[source].push_back(i); 
        adj[i].push_back(source);

        int Z; // the number of different dishes a cow can prepare
        while(Z--) {
            int foodIdentifyer;
            cin >> foodIdentifyer;

            capacity[i][N + foodIdentifyer] = 1; // cow -> food

            adj[i].push_back(N + foodIdentifyer);
            adj[N + foodIdentifyer].push_back(i);
        }
    }

    // source <-> cows <-> food <-> sink
    cout << solve(source, sink) << "\n";
    return 0;
}