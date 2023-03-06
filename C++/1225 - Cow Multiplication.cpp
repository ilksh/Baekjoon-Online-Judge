#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    string s1, s2;      // input as a string
    cin >> s1 >> s2;

    ll sum = 0;
    
    int ln1 = (int)s1.length(); // length of the first string
    int ln2 = (int)s2.length(); // length of the second string
        
    for(int i = 0; i < ln1; ++i) { // iterate all first string
        for(int j = 0; j < ln2; ++j) { // iterate all second string
            auto cur1 = s1[i]  - '0';  // change char to int
            auto cur2 = s2[j] - '0';   // change char to int
            sum += (cur1 * cur2);     // add
        }
    }
    
    cout << sum << "\n";
    return 0;
}

