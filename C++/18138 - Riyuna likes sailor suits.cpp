#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

const int MAX_N = 202;

int n, m;
vi adj[MAX_N];
vi aMatch, bMatch;
vb visited;

bool dfs(int a) {
    if (visited[a]) return false;
    visited[a] = true;

    for (int b : adj[a]) {
        if (bMatch[b] == -1 || dfs(bMatch[b])) {
            aMatch[a] = b;
            bMatch[b] = a;
            return true;
        }
    }
    return false;
}

int bipartiteMatch() {
    aMatch = vi(n + 1, -1);
    bMatch = vi(m + 1, -1); 
    int size = 0;
    for (int start = 0; start < n; ++start) { 
        visited = vb(n, false); 
        if (dfs(start)) ++size;
    }
    return size;
}

bool canAttach(double tShirt, double collar) {
    bool checkOne = (collar >= tShirt * 0.5 && collar <= tShirt * 0.75);
    bool checkTwo = (collar >= tShirt && collar <= tShirt * 1.25);
    return checkOne || checkTwo;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    vector<double> tShirts(n), collars(m);

    for (int i = 0; i < n; ++i) {
        cin >> tShirts[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> collars[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (canAttach(tShirts[i], collars[j])) {
                adj[i].push_back(j);
            }
        }
    }

    int rst = bipartiteMatch();
    cout << rst << "\n";

    return 0;
}
