#include<bits/stdc++.h>

using namespace std;

vector<int> v;

void printVector() {
    for(auto e : v) cout << e << " ";
    cout << "\n";
}

// This function solves the problem using library
void solve1(int n) {
     for (int i = 0 ; i < n; ++i) {
        int num;
        cin >> num;
        v.push_back(num);
     }
     sort(v.begin(), v.end());
     v.erase(unique(v.begin(), v.end()), v.end());
     printVector();
} 

// This function solves the problem by eliminating overlapped numbers
// with boolean array
void solve2(int n) {
    bool posUsed[n + 3]; memset(posUsed, 0, sizeof(posUsed));
    bool negUsed[n + 3]; memset(negUsed, 0, sizeof(negUsed));
    for (int i = 0 ; i < n; ++i) {
        int num;
        cin >> num;
        if (num >= 0) { // for the positive number
            if (posUsed[num]) continue;
            posUsed[num] = true;
        }
        else { // for the negative number
            if (negUsed[-num]) continue;
            negUsed[-num] = true;
        }
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    printVector();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    solve1(n);
    // solve2(n);
    
    return 0;
}
