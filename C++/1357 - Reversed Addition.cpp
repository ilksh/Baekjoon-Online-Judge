#include<bits/stdc++.h>

using namespace std;

/*
 * This function makes the number in reverse order.
 * Step 1: Change the number to String.
 * Step 2: Change the string in reverse order.
 * Step 3: Change the manipulated string to integer
 */

int rev(int n) {
    string temp = to_string(n); // Step 1
    string s = "";
    for (int i  = (int)temp.size() - 1; i >= 0 ; --i) s += temp[i]; // Step 2
    
    return stoi(s); // Step 3
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    
    int num1, num2; // number 1 and number 2
    cin >> num1 >> num2;
    auto rst = rev(num1) + rev(num2);
    cout << rev(rst) << "\n";
    
    return 0;
}

