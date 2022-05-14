#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
bool deleted[1001];

int solve() {

    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (!deleted[j]) {
                deleted[j] = 1;
                k--;
                if (k == 0)
                    return j;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(NULL);
    cin >> n >> k;

    cout << solve();
}