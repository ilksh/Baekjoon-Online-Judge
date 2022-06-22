#include<iostream>
#include<vector>

using namespace std;

const int MAX_N = 5e4 + 4;
const int MAX_B = 16;

vector<int> adj[MAX_N];
int n, m, ST[MAX_N][MAX_B], dep[MAX_N];

void makeTree(int cur, int par)
{
    for(int child : adj[cur]) {
        if(child == par) continue;

        ST[child][0] = cur;
        dep[child] = dep[cur] + 1;
        makeTree(child, cur);
    }
}

int lca(int u, int v)
{
    if(dep[u] < dep[v]) return lca(v, u);

    int diff = dep[u] - dep[v];

    for(int i=MAX_B-1; diff && i>=0; --i) {
        if((1 << i) <= diff) {
            u = ST[u][i];
            diff -= (1 << i);
        }
    }

    if(u == v) return u;

    for(int i=MAX_B-1; i>=0; --i) {
        if(ST[u][i] != ST[v]  [i]) {
            u = ST[u][i];
            v = ST[v][i];
        }
    }

    return ST[u][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n-1; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dep[1] = 0;
    makeTree(1, -1);

    for(int idx = 1; idx < MAX_B; ++idx) {
        for(int cur = 1; cur <= n; ++cur) {
            ST[cur][idx] = ST[ST[cur][idx-1]][idx-1];
        }
    }
    
    cin >> m;
    
    while(m--) {
        int node1, node2;
        cin >> node1 >> node2;
        cout << lca(node1, node2) << "\n";
    }

    return 0;
}

