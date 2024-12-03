#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi paper;
int blue, white;

void solve(int row, int col, int length) {
    int standard = paper[row][col];

    // iterate the whole area (row + lenght by col + length)
    for (int r = row; r < row + length; ++r) {
        for (int c = col; c < col + length; ++c) {
            int cur = paper[r][c];
            if (cur != standard) {
                int div = length / 2;
                solve(row, col, div);              // first quadrant
                solve(row, col + div, div);        // second quadrant
                solve(row + div, col, div);        // thrid quandrant
                solve (row + div, col + div, div); // fourth quandrant
                return;
            }
        }
    }

    standard == 0 ? white++ : blue++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    paper.assign(n,vi(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n ; ++j) {
            cin >> paper[i][j];
        } 
    }

    solve(0, 0, n);

    cout << white << "\n" << blue << "\n";
    return 0;
}