#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
vi par;

struct P {
    int x, y, r;
};

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        par[x] = y;
    }
}

bool adj(const P &a, const P &b) {
    int d = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return d <= (a.r + b.r) * (a.r + b.r);
}

int main() {
    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;

        vector<P> circles(N);
        par.resize(N);

        for (int i = 0; i < N; ++i) {
            cin >> circles[i].x >> circles[i].y >> circles[i].r;
            par[i] = i;
        }

        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (adj(circles[i], circles[j])) {
                    unite(i, j);
                }
            }
        }
        
        vector<bool> check(N, false);
        int ans = 0;

        for (int i = 0; i < N; ++i) {
            int p = find(i);
            if (!check[p]) {
                ++ans;
                check[p] = true;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
