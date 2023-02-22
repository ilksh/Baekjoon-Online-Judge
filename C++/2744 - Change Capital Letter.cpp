#include<bits/stdc++.h>

using namespace std;

/*
 * isCapital function checks whether the character is capital or not
 * It returns true when the character is capital
 * and returns false when the character is lower case
 */
bool isCapital(int asciiNum) {
    if (65 <= asciiNum && asciiNum <= 90) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    

    string s; // string s
    cin >> s; // input
    int sz = (int) s.size(); // size of string s

    for (int i = 0 ; i < sz; ++i) {
        int num = int(s[i]);           // Ascii code of current character
        if(isCapital(num)) num += 32;   // if the char is Capital > convert to lower case
        else num -= 32;                // if the char is lower case > convert to capital
        s[i] = char(num);
    }
    
    cout << s << "\n";
    return 0;
}
