#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

const int MAX_N = 303;

int n, m;
vi adj[MAX_N];
vi aMatch, bMatch;
vb visited;

bool dfs(int a) {
    if (visited[a]) return false;
    visited[a] = true;

    for (int b : adj[a]) {
        if (bMatch[b] == -1 || dfs(bMatch[b])) {
            aMatch[a] = b;
            bMatch[b] = a;
            return true;
        }
    }
    return false;
}

int bipartiteMatch() {
    aMatch = vi(n + 1, -1); 
    bMatch = vi(m + 1, -1); 
    int size = 0;
    for (int start = 1; start <= n; ++start) {
        visited = vb(n + 1, false); 
        if (dfs(start)) ++size;
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int k1, k2;
    cin >> n >> m >> k1 >> k2;

    for (int i = 0; i < k1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int rst1 = bipartiteMatch(); 

    for (int i = 0; i < MAX_N; ++i) adj[i].clear(); 

    for (int i = 0; i < k2; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int rst2 = bipartiteMatch(); 

    int healers1 = n - rst1; 
    int healers2 = n - rst2; 

    if (healers1 >  healers2) {
        cout << "네 다음 힐딱이\n";
    } else {
        cout << "그만 알아보자\n";
    }

    return 0;
}
