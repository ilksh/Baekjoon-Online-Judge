#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

const int MAX_N = 1001;

int n, m;
vi adj[MAX_N];
vi aMatch, bMatch;
vb visited;
unordered_map<string, int> memberIndex;

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
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector<string> members(m + 1);
    
    for (int i = 1; i <= m; ++i) {
        cin >> members[i];
        memberIndex[members[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            string favorite;
            cin >> favorite;
            adj[i].push_back(memberIndex[favorite]); 
        }
    }

    int maxMatch = bipartiteMatch();

    if (maxMatch == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n" << maxMatch << '\n';
    }

    return 0;
}
