#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9 + 9;
const int MAX_LENGHT = 1e3 + 3;

queue<pii> q;

int dp[MAX_LENGHT][MAX_LENGHT];
int graph[MAX_LENGHT][MAX_LENGHT];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int n,m;  // n = width, m = height

bool solve() {
    auto start = {0,0};
    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    for (int idx = 0; idx < MAX_LENGHT; ++idx) memset(dp[idx], INF, sizeof(dp[idx]));
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0 ; j < m; ++j) cin >> graph[i][j];
    }   
    
    return 0;
}