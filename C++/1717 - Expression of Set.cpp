#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 1;
const int INF = 0x3f3f3f3f;

int par[MAX_N];

int find(int x) {
    if (par[x] == x) return x;  
    par[x] = find(par[x]);
    return par[x];
}

void myUnion(int a, int b) {
    a = find(a); // find the parent of a
    b = find(b); // find the parent of b
    
    par[a] = b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i < n + 1; ++i) par[i] = i;
    for (int i = 0; i < m; ++i) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) myUnion(a, b);
        else {
            string ans = "";
            find(a) == find(b) ? ans = "YES" : ans = "NO";
            cout << ans << "\n";
        }

    }

    return 0;
}