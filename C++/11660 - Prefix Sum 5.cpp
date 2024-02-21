// #include<bits/stdc++.h>

// using namespace std;

// typedef pair<int, int> pii;
// typedef pair<pii, pii> doublePii;

// const int MAX_N = (2 << 9) + 1;
// const int MAX_M = 1e5 + 1; 

// int n;  // size of matrix
// int m; // test cases

// vector<doublePii> target;
// int mtrx[MAX_N][MAX_N];


// int solve(pii start, pii end) {
//     int startY = start.first;
//     int startX = start.second;
//     int endY = end.first;
//     int endX = end.second;
    
//     int sum = 0;
//     for (int row = startY - 1; row < endY; ++row ) {
//         for (int col = startX - 1; col < endX; ++col) {
//             sum += mtrx[row][col];
//         }       
//     }
//     return sum;
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr);
    
//     cin >> n >> m;
//     for (int row = 0; row < n; ++row) {
//         for (int col = 0; col < n; ++col)
//             cin >> mtrx[row][col];
//     }

//     while(m--) {
//         int x1, y1, x2, y2;

//         cin >> x1 >> y1 >> x2 >> y2;
//         auto start = pair{x1, y1};
//         auto end = pair{x2, y2};
//         target.push_back({start, end});
//     }

  
//     for (auto coord: target) {
//         // printf("Test: (%d, %d) ~ (%d, %d)\n", coord.first.first,coord.first.second, coord.second.first, coord.second.second);
//         int rst = solve(coord.first, coord.second);
//         cout << rst << "\n";
//     }

//     return 0;
// }

#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> doublePii;

const int MAX_N = (2 << 9) + 1;

int n;  // size of matrix
int m; // test cases

vector<doublePii> target;
int mtrx[MAX_N][MAX_N];
int dp[MAX_N][MAX_N]; // sum of (0, 0) to (i, j)

void computePrefixSum() {
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            dp[row][col] = mtrx[row][col];
            if (row > 0) dp[row][col] += dp[row - 1][col]; 
            if (col > 0) dp[row][col] += dp[row][col - 1];
            if (row > 0 && col > 0) dp[row][col] -= dp[row - 1][col - 1]; // Remove double count
        }
    }
}

int solve(pii start, pii end) {
    int startY = start.first - 1;
    int startX = start.second - 1;
    int endY = end.first - 1;
    int endX = end.second - 1;

    int sum = dp[endY][endX];
    if (startY > 0) sum -= dp[startY - 1][endX];
    if (startX > 0) sum -= dp[endY][startX - 1];
    if (startY > 0 && startX > 0) sum += dp[startY - 1][startX - 1]; 

    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col)
            cin >> mtrx[row][col];
    }

    computePrefixSum();

    while(m--) {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;
        auto start = pair{x1, y1};
        auto end = pair{x2, y2};
        target.push_back({start, end});
    }

    for (auto coord: target) {
        int rst = solve(coord.first, coord.second);
        cout << rst << "\n";
    }

    return 0;
}
