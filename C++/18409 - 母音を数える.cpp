#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    for (auto elem: vowel) {
        if (elem == c) return true;
    }
    return false;
}

int solve(string s) {
    int cnt = 0;
    for (auto elem: s) {
        if (isVowel(elem)) cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    string s;
    cin >> n;
    cin >> s;
    
    auto ans = solve(s);
    cout << ans << "\n";
    
    return 0;
}
