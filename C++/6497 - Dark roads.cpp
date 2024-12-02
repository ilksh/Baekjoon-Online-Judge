#include <bits/stdc++.h>

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

int kruskal(int &totalCost) {
    sort(edges.begin(), edges.end());

    int mstCost = 0;
    int cnt = 0;

    for (int i = 0; i < E; ++i) {
        auto curEdge = edges[i];
        int curWeight = curEdge.first;
        int start = curEdge.second.first;
        int end = curEdge.second.second;

        if (find(start) == find(end)) continue;
        unite(start, end);
        mstCost += curWeight;
        if (++cnt == V - 1) break;
    }

    return totalCost - mstCost;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    while (true) {
        cin >> V >> E;
        if (V == 0 && E == 0) break;

        edges.clear();
        par.resize(V);
        for (int i = 0; i < V; ++i) par[i] = i;

        int totalCost = 0;
        for (int i = 0; i < E; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({z, {x, y}});
             totalCost += z;
        }

        cout << kruskal(totalCost) << "\n";
    }

    return 0;
}
