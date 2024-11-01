#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, S;
vector<int> arr;

void getSubsequenceSums(int start, int end, vector<int>& sums) {
    int size = end - start + 1;
    for (int i = 0; i < (1 << size); ++i) {
        int sum = 0;
        for (int j = 0; j < size; ++j) {
            if (i & (1 << j)) {
                sum += arr[start + j];
            }
        }
        sums.push_back(sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> S;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> leftSums, rightSums;
    getSubsequenceSums(0, n / 2 - 1, leftSums);
    getSubsequenceSums(n / 2, n - 1, rightSums);

    sort(rightSums.begin(), rightSums.end());

    long long count = 0;

    for (int sum : leftSums) {
        int target = S - sum;
        auto lower = lower_bound(rightSums.begin(), rightSums.end(), target);
        auto upper = upper_bound(rightSums.begin(), rightSums.end(), target);
        count += (upper - lower);
    }

    if (S == 0) {
        count--;
    }

    cout << count << "\n";

    return 0;
}
