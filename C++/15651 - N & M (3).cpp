#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> stk;

void bt(int depth) {
    if (depth == m) {
        for (int elem : stk) cout << elem << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i < n + 1; i++) {
        stk.push_back(i); 
        bt(depth + 1); 
        stk.pop_back();   
    }
}

int main() {
    cin >> n >> m;
    bt(0); 
    return 0;
}
