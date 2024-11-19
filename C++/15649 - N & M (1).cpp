#include<bits/stdc++.h>

using namespace std;

const int MAX = 9;

int n, m;
int stk[MAX];

void bt(int depth, int visited) {
    if (depth == m) {
        for (int i = 0; i < m; ++i) cout << stk[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i < n + 1; ++i) {
        if (visited & (1 << i)) continue;
        stk[depth] = i;
        visited = visited | (1 << i);
        bt(depth + 1, visited);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m;
    bt(0, 0);
    
    return 0;
}