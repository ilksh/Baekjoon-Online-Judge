#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX_N = 2 * 1e5 + 2;
const int MAX_M = 5 * 1e5 + 5; 

int n, m; 
bool finished[MAX_N];
int dt[MAX_N];

vi adj[MAX_N], adj_rev[MAX_N]; 
stack<int> s;

void dfs(int x) {   
    dt[x] = 1;
    for (auto next : adj[x]) {
        if (!dt[next]) dfs(next);
    }
    s.push(x);
}

void dfsRev(int x) {
    finished[x] = true; 
    for (auto next : adj_rev[x]) {
        if (!finished[next]) dfsRev(next);
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) { 
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj_rev[to].push_back(from);
    }

    for (int i = 1; i <= n; ++i) {
        if (!dt[i]) dfs(i);
    }

    int scc_count = 0; 
    while (!s.empty()) {
        int x = s.top(); s.pop();
        if (!finished[x]) {
            dfsRev(x);
            scc_count++;
        }
    }

    if (scc_count == 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}