#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> ipii;

vi par;
vector<ipii> edges;

int V, E; // number of vertex and edge

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    par[x] = y;
}

int kruskal() {
    sort(edges.begin(), edges.end()); // sort graph by weight

    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < edges.size(); ++i) {
        auto curEdge = edges[i];
        int curWeight = curEdge.first;
        int from = curEdge.second.first;
        int to = curEdge.second.second;

        // cycle
        if (find(from) == find(to)) continue;

        unite(from, to);
        ans += curWeight;
        if (++cnt == V - 1) break;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    // input
    cin >> V >> E; 
    par.resize(V + 1);
    for (int i = 1; i < V + 1; ++i) par[i] = i;

    for (int i = 0; i < E; ++i) {
        int from, to, w;
        cin >> from >> to >> w;
        ipii edge = {w, {from, to}};
        edges.push_back(edge);
    }

    cout << kruskal() << "\n";

    return 0;  
}