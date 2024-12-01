#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
vi par;

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]); 
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) par[a] = b; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    par.resize(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        par[i] = i;
    }

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            int adj;
            cin >> adj;
            if (adj == 1) { 
                unite(i, j);
            }
        }
    }

    vi routes(m);
    for (int i = 0; i < m; ++i) {
        cin >> routes[i];
    }

    int standard = find(routes[0]);
    bool isPossible = true;

    for (int city : routes) {
        if (find(city) != standard) {
            isPossible = false;
            break;
        }
    }
    
    if (isPossible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
