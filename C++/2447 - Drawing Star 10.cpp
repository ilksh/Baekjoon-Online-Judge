#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<char>> vvc;

void solve(vvc& board, int x, int y, int size) {
    if (size == 1) {
        board[x][y] = '*';
        return;
    }

    int subSize = size / 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // middle part = empty
            if (i == 1 && j == 1) continue;
            solve(board, x + i * subSize, y + j * subSize, subSize);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int N;
    cin >> N;

    vvc board(N, vector<char>(N, ' '));
    solve(board, 0, 0, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}