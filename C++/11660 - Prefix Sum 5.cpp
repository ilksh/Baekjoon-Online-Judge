#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> doublePii;

const int MAX_N = (2 << 9) + 1;
const int MAX_M = 1e5 + 1; 

int n;  // size of matrix
int m; // test cases

vector<doublePii> target;
int mtrx[MAX_N][MAX_N];

int solve(pii start, pii end) {
    int sum = 0;
    int startX;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout << MAX_N << "\n";

    cin >> n >> m;
    while(m--) {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;
        auto start = pair{x1, y1};
        auto end = pair{x2, y2};
        target.push_back({start, end});
    }
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col)
            cin >> mtrx[row][col];
    }
}