#include<bits/stdc++.h>

using namespace std;

typedef stack<int> si;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int MAX = 4 * (1e5) + 2;
constexpr int trueX(int x) {return x << 1;}
constexpr int falseX(int x) {return (x << 1) | 1;}
constexpr int notX(int x) {return x ^ 1;}

int id, dt[MAX];
bool finished[MAX];
vi adj[MAX];
vvi SCCs;
si s;
int sccID[MAX];

int dfs(int x) {
    dt[x] = ++id;
    s.push(x);

    int par = dt[x];

    for (auto next: adj[x]) {
        if (dt[next] == 0) par = min(par, dfs(next));
        else if (!finished[next]) par = min(par, dt[next]);
    }

    if (par == dt[x]) {
        vi scc;
        while(true) {
            auto t = s.top(); s.pop();
            scc.push_back(t);
            finished[t] = true;
            sccID[t] = SCCs.size();
            if (t == x) break;
        }
        SCCs.push_back(scc);
    }
    return par;
}

void initialize() {
    id = 0;
    memset(dt, 0, sizeof(dt));
    memset(finished, false, sizeof(finished));
    for (int i = 0; i < MAX; ++i) adj[i].clear();
    SCCs.clear();
    s = si();
    memset(sccID, 0, sizeof(sccID));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m;
    while(cin >> n >> m ) {
        if (n == 0 && m == 0) break;

        initialize();

        for (int i = 0; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            u = (u > 0) ? trueX(u) : falseX(-u);
            v = (v > 0) ? trueX(v) : falseX(-v);

            adj[notX(u)].push_back(v);
            adj[notX(v)].push_back(u);
        }

        for (int i =2; i < n * 2 + 2; ++i) {
            if (dt[i] == 0) dfs(i);
        }

        bool work = true;
        for (int i = 1; i < n + 1; ++i) {
            auto t = trueX(i);
            auto f = falseX(i);
            if (sccID[t] == sccID[f]) {
                work = false;
                break;
            }
        }
        if (work) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}