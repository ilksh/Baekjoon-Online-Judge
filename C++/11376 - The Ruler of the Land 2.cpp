#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 1e3 + 3;

typedef vector<int> vi;
typedef vector<bool> vb;


vi visited, aMatch, bMatch;
vi adj[MAX_N];

int n, m; // number of people and job respectively

bool dfs(int a) {
    if (visited[a]) return false;
    visited[a] = true;

    for (auto b : adj[a]) {
        int matchedNode = bMatch[b];
        if (bMatch[b] == -1 || dfs(matchedNode)) {
            aMatch[a] = b;
            bMatch[b] = a;
            return true;
        }
    }
    return false;
}

int bipartiteMatching() {
    aMatch = vi(2 * n + 1, -1);
    bMatch = vi(m + 1, -1);
    int size = 0;

    for (int start = 1; start < n + 1; ++start) {
        for (int rep = 0; rep < 2; ++rep) {
            visited = vi(2 * n + 1, false);
            if (dfs(start)) ++ size;
        }
    }
    return size;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i < n + 1; ++i) {
        int numJobs;
        cin >> numJobs;
        for (int j = 0; j < numJobs; ++j) {
            int job;
            cin >> job; 
            adj[i].push_back(job);
        }
    }

    cout << bipartiteMatching() << "\n";
    return 0;   
}