#include<bits/stdc++.h>

using namespace std;

struct Circle {
    int x, y, r;
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        Circle c1, c2;
        cin >> c1.x >> c1.y >> c1.r >> c2.x >> c2.y >> c2.r;

        double d = sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2));

        if (d == 0 && c1.r == c2.r) {
            cout << -1 << endl;
        } else if (d > c1.r + c2.r || d < abs(c1.r - c2.r)) {
            cout << 0 << endl;
        } else if (d == c1.r + c2.r || d == abs(c1.r - c2.r)) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }

    return 0;
}
