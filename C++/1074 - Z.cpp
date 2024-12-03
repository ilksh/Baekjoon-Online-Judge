#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi board;

void fillBoard(int r, int c, int length, int &value) {
    if (length == 1) { // Base case: single cell
        board[r][c] = value++;
        return;
    }

    int div = length / 2;

    fillBoard(r, c, div, value);            // 1st quadrant
    fillBoard(r, c + div, div, value);      // 2nd quadrant
    fillBoard(r + div, c, div, value);      // 3rd quadrant
    fillBoard(r + div, c + div, div, value); // 4th quadrant
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, row, col;
    cin >> N >> row >> col;

    int size = 1 << N; // 2^N
    board.assign(size, vi(size, 0));

    int value = 0;
    fillBoard(0, 0, size, value);

    cout << board[row][col] << "\n";
    return 0;
}
