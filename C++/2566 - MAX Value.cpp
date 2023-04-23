#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;  // {row, col}
typedef pair<int, pii> ipii; // {max value, {row, col}}
const int MAX_SIZE = 1e1 + 1;
int arr[MAX_SIZE][MAX_SIZE];

void input() { // input the 9 by 9 matrix
    for (int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cin >> arr[i][j];
        }
    }
}

ipii solve() { //
    int mx = -1; // greedy approach
    pii coord = {NULL, NULL};
    for (int i = 0; i < 9; ++i) { // iteratiing all rows
        for (int j = 0; j < 9; ++j) { // itrating all columns
            auto cur = arr[i][j]; // current value
            if (cur > mx) { // if find a new maximum
                mx = cur; // update the maximum value
                coord = {i + 1,j + 1}; // update the coordinate of maximum value
            }
        }
    }
    return {mx, coord}; // return {max value, {row, col}}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    input();
    auto rst = solve();
    cout << rst.first << "\n";
    cout << rst.second.first << " " << rst.second.second << "\n";
    return 0;
}

