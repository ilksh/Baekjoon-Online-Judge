#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAX_N = 1e5;

int sum;
int stop;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, s;
    int v[MAX_N];
    int mn = INF;
    
    cin >> n >> s;
    
    for(int i = 0; i < n; ++i) { // iterate all index
        cin >> v[i];
        sum += v[i];
        while(true) {
            if (sum < s || stop > i) break;
            if(mn > i - stop + 1) mn = i - stop + 1; // update information
            sum -= v[stop++];
        }
    }
    
    auto rst = (mn >= INF) ? 0 : mn;
    cout << rst << "\n";
    
    return 0;
}
