#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

const int MAX_N = 1e2 + 2;

int n, m; // number of node and edges
vi adj[MAX_N]; // person -> laptop
vi aMatch, bMatch; // matching status
vb visited;

bool dfs(int a) {
    if (visited[a]) return false;
    visited[a] = true;

    for (auto b : adj[a]) { // iterate all adjacent nodes
        if (bMatch[b] == -1) { // not matched
            aMatch[a] = b; 
            bMatch[b] = a;
            return true;
        }
        else { // alreayd matched
            int curPerson = bMatch[b];
            if (dfs(curPerson)) { // check curPerson be matched with other laptop
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        }
    }
    return false;
}

int bipartiteMatching() {
    aMatch = vi(n + 1, -1);
    bMatch = vi(n + 1, -1);
    int size = 0;

    for (int start = 1; start < n + 1; ++start) {
        visited = vb(n + 1, false);
        if (dfs(start)) ++ size;
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int person, laptop;
        cin >> person >> laptop;
        adj[person].push_back(laptop);
    }

    int rst = bipartiteMatching();

    cout << rst << "\n";
    return 0;
}