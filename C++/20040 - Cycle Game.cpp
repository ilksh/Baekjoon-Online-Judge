#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
vi par, rank_vec;

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false; // cycle already exist

    if (rank_vec[a] < rank_vec[b]) swap(a, b); 
    par[b] = a;
    if (rank_vec[a] == rank_vec[b]) rank_vec[a]++;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    par.resize(n);
    rank_vec.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;

        if (!unite(u, v)) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
    return 0;
}
