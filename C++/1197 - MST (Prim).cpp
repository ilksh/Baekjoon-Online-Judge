#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 1e4 + 4;

vector<pii> graph[MAX];
bool visited[MAX];

int V, E; // number of node and Edge

int prim() {
    priority_queue<pii> pq;
    int ans = 0;

    visited[1] = true;
    for (int i = 0; i < graph[1].size(); ++i) {
        int to = graph[1][i].first;
        int curW = graph[1][i].second;
        pq.push({-curW, to});
    }

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        int curNode= cur.second;
        int curWeight = -cur.first;

        if (visited[curNode]) continue;;

        ans += curWeight;
        visited[curNode] = true;

        for (int i = 0; i < graph[curNode].size(); ++i) {
            int nextWeight = -graph[curNode][i].second;
            int nextNode = graph[curNode][i].first;
            pq.push({nextWeight, nextNode});
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E;
    
    for (int i = 0; i < E; ++i) {
        int from, to, w;
        cin >> from >> to >> w;
        graph[from].push_back({to, w});
        graph[to].push_back({from, w});
    }

    cout << prim() << "\n";
    return 0;
}