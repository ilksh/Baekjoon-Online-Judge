#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX_N = 1e2 + 2;
const int INF = 1e9;

int n;
int cost[MAX_N];
bool finished[MAX_N];

int dt[MAX_N], sccID[MAX_N]; // discovery time, SCC ID
vi adj[MAX_N], adjRev[MAX_N]; // original graph, reversed graph

stack<int> s;
vvi SCCs; // list of SCCs

void dfs(int x) {
    dt[x] = 1;
    for (auto e: adj[x]) {
        if (!dt[e]) dfs(e);
    }
    s.push(x); // push node that finished traverse
}

void dfsRev(int x, int sccNum) {
    finished[x] = true;
    sccID[x] = sccNum; // label the group
    SCCs[sccNum].push_back((x)); // add node to the group
    for (auto e: adjRev[x]) {
        if (!finished[e]) dfsRev(e, sccNum);
    }
}

int solve() {
    int n;
    cin >> n;

    for (int i = 1; i < n + 1; ++i) {
        cin >> cost[i];
    }

    for (int i = 1; i < n + 1; ++i) {
        string temp;
        cin >> temp;

        for (int j = 0; j < n; ++j) {
            if (temp[j] == '1') {
                adj[i].push_back(j + 1);
                adjRev[j + 1].push_back(i);
            }
        }
    }

    for (int i = 1; i < n + 1; ++i) {
        if (!dt[i]) dfs(i);
    }

    int sccCnt = 0;

    while (!s.empty()) {
        auto x = s.top(); s.pop();
        if (!finished[x]) {
            SCCs.push_back(vi ()); // make empty list
            dfsRev(x, sccCnt++);
        }
    } // from here, constructing SCCs done

    int sum = 0; 

    for (int i = 0; i < sccCnt; ++i) {
        int mn = INF;
        for (auto node: SCCs[i]) { // iterate all nodes in a scc group
            mn = min(mn, cost[node]);
        }
        sum += mn;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    cout << solve() << "\n";

    return 0;
}