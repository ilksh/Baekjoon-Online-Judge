#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

constexpr int MAX = 2000; 
constexpr int trueX(int x) { return x << 1; }
constexpr int falseX(int x) { return (x << 1) | 1; }
constexpr int notX(int x) { return x ^ 1; }


int n, m;
vi adj[MAX * 2];
int id, dt[MAX * 2], sccId[MAX * 2];
bool finished[MAX * 2];
stack<int> s;
vvi SCCs;

int dfs(int x) {
    dt[x] = ++id;
    s.push(x);

    int parent = dt[x];
    for (int next : adj[x]) {
        if (!dt[next]) parent = min(parent, dfs(next));
        else if (!finished[next]) parent = min(parent, dt[next]);
    }

    if (parent == dt[x]) {
        vi scc;
        while (true) {
            int t = s.top(); s.pop();
            scc.push_back(t);
            finished[t] = true;
            sccId[t] = SCCs.size();
            if (t == x) break;
        }
        SCCs.push_back(scc);
    }
    return parent;
}

void addImplication(int u, int v) {
    adj[u].push_back(v);
}

void addOR(int u, int v) {
    addImplication(notX(u), v); // ¬u → v
    addImplication(notX(v), u); // ¬v → u
}

bool solve2SAT(int vars) {
    for (int i = 0; i < vars * 2; ++i)
        if (!dt[i]) dfs(i);

    for (int i = 0; i < vars; ++i)
        if (sccId[trueX(i)] == sccId[falseX(i)])
            return false;

    return true;
}

int main() {
    cin >> n >> m;
    vector<string> museum(n);
    for (int i = 0; i < n; ++i) cin >> museum[i];

    int vars = n + m; 

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (museum[i][j] == '*') {
                // jewel: (x_r || y_c) && (!x_r || !y_c)
                addOR(trueX(i), trueX(n + j)); // x_r || y_c
                addOR(falseX(i), falseX(n + j)); // !x_r || !y_c
            }
            else if (museum[i][j] == '#') {
                // location: (x_r || !y_c) && (!x_r || y_c)
                addOR(trueX(i), falseX(n + j)); // x_r || !y_c
                addOR(falseX(i), trueX(n + j)); // !x_r || y_c
            }
        }
    }

    if (solve2SAT(vars)) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}
