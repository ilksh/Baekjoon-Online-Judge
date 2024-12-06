#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e2 + 2;

int outlet[MAX]; 
int schedule[MAX]; 
int n, k; 

int solve() {
    int ans = 0;

    for (int i = 0; i < k; ++i) {
        bool flag = false;


        for (int j = 0; j < n; ++j) {
            if (outlet[j] == schedule[i]) {
                flag = true;
                break;
            }
        }

        if (flag) continue;

        for (int j = 0; j < n; ++j) {
            if (outlet[j] == 0) {
                outlet[j] = schedule[i];
                flag = true;
                break;
            }
        }

        if (flag) continue;

        int last = -1;
        int idxToRemove = -1; 

        for (int j = 0; j < n; ++j) {
            int temp = 0;
            for (int a = i + 1; a < k; ++a) {
                if (schedule[a] == outlet[j]) break;
                temp++;
            }

            if (temp > last) {
                last = temp;
                idxToRemove = j;
            }
        }

        outlet[idxToRemove] = schedule[i];
        ans++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k; 
    for (int i = 0; i < k; ++i) cin >> schedule[i]; 

    fill(outlet, outlet + n, 0);

    cout << solve() << "\n";
    return 0;
}
