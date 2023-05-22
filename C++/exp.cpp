#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v;

    for (int i = 10; i >= 0 ; --i) v.push_back(i);

    for (auto e : v) cout << e << " ";

    return 0;
}