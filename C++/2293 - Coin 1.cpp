#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> coins;

    for (int i = 0; i < n; ++i) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    int dp[k + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1; 

    for (int i = 0; i < n; ++i) {
        int coin = coins[i];
        for (int j = coin; j < k + 1; ++j) {
            dp[j] += dp[j - coin];
        }
    }
    
    cout << dp[k] << "\n";
    
    return 0;
}
