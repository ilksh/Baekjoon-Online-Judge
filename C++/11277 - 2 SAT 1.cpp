#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX = 20000 + 10;
constexpr int trueX(int x) {return x << 1;};
constexpr int falseX(int x) {return (x << 1) | 1;}
constexpr int notX(int x) {return x ^ 1;}

int id = 0;
int dt[MAX];    // discovery time
int sccID[MAX]; // SCC ID for each node
bool finished[MAX];

vi adj[MAX];    // adjacent list
vvi SCCs;
stack<int> s;

int dfs(int x) {
    dt[x] = ++id;
    s.push(x);

    int parent = dt[x];
    for (auto next: adj[x]) {
        if (dt[next] == 0) {
            parent = min(parent, dfs(next));
        }
        else if (!finished[next]) {
            parent = min(parent, dt[next]);
        }
    }

    // case hwne x is the root of current SCC
    if (parent == dt[x]) {
        vi scc;
        while (true) {
            auto t = s.top(); s.pop();
            scc.push_back(t);
            finished[t] = true;
            sccID[t] = SCCs.size();
            if (t == x) break;
        }
        SCCs.push_back(scc);
    }
    return parent;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; // number of variables and clauses
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        
        u = (u > 0) ? trueX(u) : falseX(u);
        v = (v > 0) ? trueX(v) : falseX(v);
        
        adj[notX(u)].push_back(v); // ¬u → v
        adj[notX(v)].push_back(u); // ¬v → u
    }

    for (int i = 1 * 2; i < n * 2 + 1; ++i) {
        if (dt[i] == 0) dfs(i);
    }

    for (int i = 1; i < n + 1; ++i) {
        if (sccID[trueX(i)] == sccID[falseX(i)]) {
            cout << "0\n";
            return 0;
        }
    }
    cout << "1\n"; 
    return 0;
}