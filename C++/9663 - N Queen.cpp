#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 4 * 1e4;

bool col[MAX_N], dia1[MAX_N], dia2[MAX_N];

int ans, n;

void backTracking(int y){
    if(y == n){
        ans += 1;
        return;
    }
    
    for(int x = 0; x < n; ++x){
        bool possibleToMove = !col[x] && !dia1[x+y] && !dia2[x-y+n-1];
        if(possibleToMove){
            col[x]  = true;
            dia1[x + y] = true;
            dia2[x - y + n - 1] = true;
            
            backTracking(y + 1);
            
            col[x]  = false;
            dia1[x + y] = false;
            dia2[x - y + n - 1] = false;
        }
    }
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
   
    cin >> n;
    backTracking(0);
    cout << ans << "\n";
    
    return 0;
}
