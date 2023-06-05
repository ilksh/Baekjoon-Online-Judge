#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    ll n;
    cin >> n;

    ll low = 0;
    ll high = n;

    while (low + 1 < high) {
        ll mid = (low + high) / 2;
        if (mid >= 3037000500 || mid * mid >= n) high = mid;
        else low = mid;
    }
    cout << high;

    return 0;
}