#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> stk;

void bt(int depth) {
    if (stk.size() == m) {
        for (int elem : stk) cout << elem << " ";
        cout << '\n';
        return;
    }

    for (int i = depth; i < n + 1; i++) {
        stk.push_back(i); 
        bt(i); 
        stk.pop_back();   
    }
}

int main() {
    cin >> n >> m;
    bt(1); 
    return 0;
}
