#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 4005;
constexpr int trueX(int x) { return x << 1; }
constexpr int falseX(int x) { return (x << 1) | 1; }
constexpr int notX(int x) { return x ^ 1; }

int id, dt[MAX], sccID[MAX];
bool finished[MAX];
vector<int> adj[MAX];
vector<vector<int>> SCCs;
stack<int> s;

void initialize(int n) {
    id = 0;
    memset(dt, 0, sizeof(dt));
    memset(finished, false, sizeof(finished));
    memset(sccID, 0, sizeof(sccID));
    for (int i = 0; i <= n * 2 + 1; ++i) {
        adj[i].clear();
    }
    SCCs.clear();
    while (!s.empty()) s.pop();
}

int dfs(int x) {
    dt[x] = ++id;
    s.push(x);

    int parent = dt[x];
    for (int next : adj[x]) {
        if (dt[next] == 0) {
            parent = min(parent, dfs(next));
        } else if (!finished[next]) {
            parent = min(parent, dt[next]);
        }
    }

    if (parent == dt[x]) {
        vector<int> scc;
        while (true) {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            sccID[t] = SCCs.size();
            if (t == x) break;
        }
        SCCs.push_back(scc);
    }
    return parent;
}

bool solve_2SAT(int n) {
    for (int i = 2; i <= n * 2 + 1; ++i) {
        if (dt[i] == 0) dfs(i);
    }

    for (int i = 1; i <= n; ++i) {
        if (sccID[trueX(i)] == sccID[falseX(i)]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int scenario = 1; scenario <= t; ++scenario) {
        int n, m;
        cin >> n >> m;

        initialize(n);

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;

            adj[notX(trueX(u))].push_back(trueX(v));
            adj[trueX(u)].push_back(notX(trueX(v)));
            adj[notX(trueX(v))].push_back(trueX(u));
            adj[trueX(v)].push_back(notX(trueX(u)));
        }

        cout << "Scenario #" << scenario << ":\n";
        if (solve_2SAT(n)) {
            cout << "No suspicious bugs found!\n";
        } else {
            cout << "Suspicious bugs found!\n";
        }
        cout << "\n";
    }

    return 0;
}
