#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> ipii;

vi par;
vector<ipii> edges;

int V, E;

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x != y) par[x] = y;
}

int kruskal() {
    sort(edges.begin(), edges.end()); 

    int ans = 0;
    int cnt = 0;
    int maxWeight = 0;

    for (int i = 0; i < E; ++i) {
        auto curEdge = edges[i];
        auto curWeight = curEdge.first;
        auto start = curEdge.second.first;
        auto end = curEdge.second.second;

        if (find(start) == find(end)) continue;

        unite(start, end);
        ans += curWeight;
        maxWeight = curWeight; 
        if (++cnt == V - 1) break;
    }
    return ans - maxWeight; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E;
    par.resize(V + 1);
    for (int i = 1; i < V + 1; ++i) par[i] = i;

    for (int i = 0; i < E; ++i) {
        int start, end, w;
        cin >> start >> end >> w;
        ipii edge = {w, {start, end}};
        edges.push_back(edge);
    }

    int result = kruskal();
    cout << result << "\n";

    return 0;
}
