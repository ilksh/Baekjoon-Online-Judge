#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;
const int INF = 1e9;
int dp[MAX_N];

int solve(int n) {
    if (n < 0) return INF; 
    if (n <= 0) return 0; 

    int& ret = dp[n];
    if (ret != -1) return ret; 

    int useTwo = solve(n - 2) + 1;
    int useFive = solve(n - 5) + 1;

    return ret = min(useTwo, useFive);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    memset(dp, -1, sizeof(dp));

    int ans = solve(N);
    if (ans >= INF) ans = -1;
    
    cout << ans << "\n";

    return 0;
}
