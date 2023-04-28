#include<bits/stdc++.h>
using namespace std;

string solve(int n) {
    int q = n / 5;
    int r = n % 5;
    string rst = "";
    for (int i  = 0; i < q; ++i) rst += "V";
    for (int i  = 0; i < r; ++i) rst += "I";
    return rst;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    auto s = solve(n);
    cout << s << "\n";
    return 0;
}
