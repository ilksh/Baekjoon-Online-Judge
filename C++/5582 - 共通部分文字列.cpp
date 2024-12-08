#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int solve(const string &A, const string &B) {
    int n = A.size(), m = B.size();
    vvi dp(n + 1, vi(m + 1, 0)); // DP table
    int maxLength = 0; 

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            if (A[i - 1] == B[j - 1]) { // If characters match
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            } else {
                dp[i][j] = 0; // Reset if characters do not match
            }
        }
    }

    return maxLength;
}

int main() {
    string A, B;
    cin >> A >> B;

    cout << solve(A, B) << "\n";

    return 0;
}
