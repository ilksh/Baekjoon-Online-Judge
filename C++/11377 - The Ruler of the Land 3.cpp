#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1003;

typedef vector<int> vi;

vi visited, aMatch, bMatch;
vi adj[MAX_N];

int n, m, k; 
int extraCount; // track the number of employee who can afford at most 2 jobs

bool dfs(int a, bool isSecondAttempt = false) {
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
    aMatch = vi(n + 1, -1);
    bMatch = vi(m + 1, -1);
    int size = 0;

    for (int start = 1; start <= n; ++start) {
        visited = vi(n + 1, false);
        if (dfs(start)) ++size;
    }

    extraCount = 0;
    for (int start = 1; start <= n; ++start) {
        if (extraCount >= k) break; 

        visited = vi(n + 1, false);
        if (dfs(start)) {
            ++size;
            ++extraCount;
        }
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i) {
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
