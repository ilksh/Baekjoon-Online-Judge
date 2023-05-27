#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v;
    for (int i = 0 ; i < 10; ++i) v.push_back(i * 10);
    for (auto elem : v) cout << elem << " ";
    cout << "\n"; 
    return 0;
}