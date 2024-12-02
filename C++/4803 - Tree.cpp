#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi par, visited;
vvi adj;
bool hasCycle;

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]); // Path compression
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) par[x] = y; // Simply attach one tree under another
    
}

void dfs(int node, int parent) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) dfs(neighbor, node);
        else if (neighbor != parent) hasCycle = true; 
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int caseCnt = 1;
    int n, m;

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        par.resize(n + 1);
        adj.assign(n + 1, vi());
        visited.assign(n + 1, false);
        for (int i = 1; i < n + 1; ++i) par[i] = i;

        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            unite(x, y);
        }

        set<int> roots; 
        for (int i = 1; i < n + 1; ++i) roots.insert(find(i));

        int treeCnt = 0;

        for (int root : roots) { // cycle check
            hasCycle = false;

            for (int i = 1; i <= n; ++i) {
                if (find(i) == root && !visited[i]) {
                    dfs(i, -1);
                    break;
                }
            }

            if (!hasCycle) treeCnt++;
        }

        if (treeCnt == 0) {
            printf("Case %d: No trees.\n", caseCnt);
        } else if (treeCnt == 1) {
            printf("Case %d: There is one tree.\n", caseCnt);
        } else {
            printf("Case %d: A forest of %d trees.\n", caseCnt, treeCnt);
        }
        caseCnt++;
    }

    return 0;
}
