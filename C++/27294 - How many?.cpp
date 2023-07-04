#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int t; // time 
    bool s; // boolean variable whether eating with drink
    cin >> t >> s; 
    // lunch time is 12 ~ 16
    bool lunch = ((12 <= t) && (t <= 16));
    // if customer eats sushi with drink or it is not a lunch time
    if (s || !lunch) cout << 280 << "\n";
    // eats sushi without drink and it is lunch time
    else cout << 320 << "\n";
    return 0;
}