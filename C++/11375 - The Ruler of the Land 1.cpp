#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

const int MAX_N = 1e3;

vb visited;
vi adj[MAX_N];
vi aMatch, bMatch;

int n, m; // number of people and job

bool dfs(int a) {
    if (visited[a]) return false;
    visited[a] = true;

    for (auto b: adj[a]) {
        if (bMatch[b] == -1) {
            aMatch[a] = b;
            bMatch[b] = a;
            return true;
        }
        else {
            int matchedPerson = bMatch[b];
            if (dfs(matchedPerson)){
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        }
    }
    return false;
}   
int bipartiteMatch() {
    aMatch = vi(n + 1, -1);
    bMatch = vi(n + 1, -1);
    int size = 0;

    for (int start = 1; start < n + 1; ++start) {
        visited = vb(n + 1, false);
        if (dfs(start)) ++size;
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

    cout << bipartiteMatch() << "\n";
    return 0;
}