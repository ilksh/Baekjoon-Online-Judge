#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
const int MAX_K = 1e4 + 4;
const int INF = 1e9;

int solve(vi& coins, int k) {
    int dp[k + 1];
    for (int i = 0; i < k + 1; ++i) dp[i] = INF;

    dp[0] = 0;
    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        for (auto coin : coins) {
            // prevent overlow
            if (coin > k - cur) continue;
            int next = cur + coin;
            int nextCost = dp[cur] + 1;

            if (nextCost < dp[next]) {
                dp[next] = nextCost;
                q.push(next);
            }
        }
    }
    return dp[k];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vi coins;
    for (int i = 0 ; i < n; ++i) {
        int coin;   
        cin >> coin;
        coins.push_back(coin);
    }
    int rst = solve(coins, k);
    if (rst == INF) rst = -1;
    cout << rst << "\n";

    return 0;
}