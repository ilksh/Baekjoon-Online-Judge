#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 21;

int coordinate[2][MAX_N];
bool visited[MAX_N];

int n;
double rst;

// aCb
void solve(int idx, int a, int b)
{
    if(b == 0)
    {
        double xSum = 0;
        double ySum = 0;
        
        for(int i=0; i<n; ++i)
        {
            if(visited[i])
            {
                xSum += coordinate[0][i];
                ySum += coordinate[1][i];
            }
            
            else
            {
                xSum -= coordinate[0][i];
                ySum -= coordinate[1][i];
            }
        }
        
        rst = min(rst, sqrt(xSum * xSum + ySum * ySum));
        return;
    }
    
    if(idx == n)
        return;
    
    visited[idx] = true;
    solve(idx+1, a, b-1);
    
    visited[idx] = false;
    solve(idx+1, a, b);
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc; // test case
    cin >> tc;
    
    while(tc--)
    {
        rst = 1e9;
        cin >> n;
        
        // coordinate[0] = x coordinate, coordinate[1] = y coordinate
        for(int i=0; i<n; ++i)
            cin >> coordinate[0][i] >> coordinate[1][i];
        
        solve(0, n, n/2);
        
        cout << fixed;
        cout.precision(12);
        cout << rst <<"\n";
    }
    
    return 0;
}
