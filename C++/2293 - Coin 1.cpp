#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        // Initialize the dp array with the value INF, as initially, we assume
        // that it's not possible to form any amount
        for(int i = 0; i <= amount; ++i) dp[i] = 0;

        // Base case: 0 coins are needed to make the amount 0
        dp[0] = 0;
        queue<int> q;
        q.push(0);

        // BFS-like approach to build up the solutions for each amount
        while(!q.empty()) {
            int cur = q.front(); q.pop();

            for (auto coin : coins) {
                // Prevent integer overflow
                if (coin > amount - cur) continue;

                int next = cur + coin;
                int nextCost = dp[cur] + 1;
                
                q.push(next);
                // Update dp[next] if a better solution is found
                if (nextCost < dp[next]) {
                    dp[next] = nextCost;
                    q.push(next);
                }
            }
        }

        // If dp[amount] is still INF, it means the amount cannot be formed
        return dp[amount];
    }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k;   
    cin >> n >> k;

    vector<int> coins;
    for (int i = 0; i < n; ++i) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    auto rst = coinChange(coins, k);
    cout << rst << "\n";
    return 0;
}