#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pii> plpii;

const int MAX_N = 1e5;
int a[MAX_N];

plpii solve(int a[], int left, int right) {
    if (left == right) return {(ll) a[left] * a[left], {left, left}};

    int mid = (left + right) / 2;
    
    auto leftRst = solve(a, left, mid);
    auto rightRst = solve(a, mid + 1, right);
    ll mx = max(leftRst.first, rightRst.first);

    pii indices = leftRst.first >= rightRst.first ? leftRst.second : rightRst.second;
    
    int leftIdx = mid;
    int rightIdx = mid + 1;

    int mn = min(a[leftIdx], a[rightIdx]);
    ll curSum = a[leftIdx] + a[rightIdx];

    if (curSum * mn > mx) {
        mx = curSum * mn;
        indices = {leftIdx, rightIdx};
    }
    
    while(left < leftIdx || rightIdx < right) {
        if (rightIdx < right && (leftIdx == left || a[leftIdx - 1] < a[rightIdx + 1])) {
            rightIdx++;
            curSum += a[rightIdx];
            mn = min(mn, a[rightIdx]);
        } else {
            leftIdx--;
            curSum += a[leftIdx];
            mn = min(mn, a[leftIdx]);
        }

        if (curSum * mn > mx) {
            mx = curSum * mn;
            indices = {leftIdx, rightIdx};
        }
    }

    return {mx, indices};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;

    // input
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    auto rst = solve(a, 0, n - 1);
    cout << rst.first << "\n";
    cout << rst.second.first + 1 << " " << rst.second.second + 1 << "\n";

    return 0;
}
