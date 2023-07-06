#include<bits/stdc++.h>

using namespace std;


string check(string line) {
    stack<char> stk;
    
    for (auto elem : line) { // iterate all characters in line
        
        if (elem == '(') stk.push(elem);
    
        else if (elem == '[') stk.push(elem);
        
        else if (elem == ')') {
            // when stack is empty or unable to match
            if (stk.empty() || stk.top() != '(') return "no";
            // proceed to the next char
            else stk.pop();
        }
        else if (elem == ']') {
            // when stack is empty or unable to match
            if (stk.empty() || stk.top() != '[') return "no";
            // proceed to the next char
            else stk.pop();
        }
    }

    // if there is remaining character(s)
    if (!stk.empty()) return "no";
    
    // stack is empty = all parenthesises are matched
    else return "yes";
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string line = "";

    while (line != ".") {
        getline(cin, line);
        cout << check(line) << "\n";
    }

    return 0;
}
