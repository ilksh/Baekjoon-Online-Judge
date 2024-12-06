#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;
int dp[MAX_N];
vector<int> A;

int solveTopDown(int idx) {
    int& ret = dp[idx];

    if (ret!= -1) return dp[idx]; 
    ret = 1;

    for (int next = idx + 1; next < A.size(); ++next) {
        if (A[idx] > A[next]) { 
            dp[idx] = max(dp[idx], solveTopDown(next) + 1);
        }
    }

    return dp[idx];
}

void topDown() {
    int N;
    cin >> N;
    A.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    memset(dp, -1, sizeof(dp));
    int result = 0;

    for (int i = 0; i < N; ++i) {
        result = max(result, solveTopDown(i)); 
    }

    cout << result << "\n";
}

void bottomUp() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    memset(dp, 1, sizeof(dp));

    for (int i = N - 1; i >= 0; --i) { 
        for (int j = i + 1; j < N; ++j) {
            // decreasing
            if (A[i] > A[j]) dp[i] = max(dp[i], dp[j] + 1);   
        }
    }

    int result = 0;
    for (int i = 0; i < N; ++i) {
        result = max(result, dp[i]); 
    }

    cout << result << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    topDown();
    // bottomUp();

    return 0;
}
