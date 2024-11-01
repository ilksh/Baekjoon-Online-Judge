#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 1e5;
int a[MAX_N];

ll solve(int a[], int left, int right) {
    if (left == right) return (ll) a[left] * a[left];

    int mid = (left + right) / 2;
    ll mx = max(solve(a, left, mid), solve(a, mid + 1, right)); 
    
    int leftIdx = mid;
    int rightIdx = mid + 1;

    int mn = min(a[leftIdx], a[rightIdx]);
    ll curSum = a[leftIdx] + a[rightIdx];

    mx = max(mx, curSum * mn);
    
    while(left < leftIdx || rightIdx < right ) {
        if (rightIdx < right && (leftIdx == left || a[leftIdx- 1] < a[rightIdx+ 1])) {
            rightIdx++;
            curSum += a[rightIdx];
            mn = min(mn, a[rightIdx]);
        }
        else {
            leftIdx--;
            curSum+=a[leftIdx];
            mn = min(mn, a[leftIdx]);
        }
        mx = max(mx, curSum * mn);
    }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;

    // input
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << solve(a, 0, n - 1) << "\n";

    return 0;
}