#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi paper;
int neg = 0, zero = 0, pos = 0; // Count variables

void solve(int row, int col, int length) {
    int standard = paper[row][col];
    bool isUniform = true;

    // Check if all values in the current segment are the same
    for (int r = row; r < row + length; ++r) {
        for (int c = col; c < col + length; ++c) {
            if (paper[r][c] != standard) {
                isUniform = false;
                break;
            }
        }
        if (!isUniform) break;
    }

    if (isUniform) {
        // Increment the appropriate counter
        if (standard == -1) neg++;
        else if (standard == 0) zero++;
        else if (standard == 1) pos++;
    } else {
        // Divide into 9 parts
        int div = length / 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                solve(row + i * div, col + j * div, div);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    paper.assign(N, vi(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, N);

    cout << neg << "\n";
    cout << zero << "\n";
    cout << pos << "\n";

    return 0;
}
