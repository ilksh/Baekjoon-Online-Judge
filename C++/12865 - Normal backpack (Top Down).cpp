#include <iostream>
#include<string.h>
using namespace std;
const int MAX_N = 101;
const int MAX_K = 1e5 + 1;
int dp[MAX_N][MAX_K];
int w[MAX_N];   
int v[MAX_N];  
int n, k;       

int solve(int idx, int capacity)
{   

    if (idx== n)
        return 0;

    int& result = dp[idx][capacity];
    if (result != -1)
        return result;
     
    result = solve(idx + 1, capacity); 

    if (w[idx] <= capacity)           
        result = max(result, solve(idx + 1, capacity - w[idx]) + v[idx]);
    

    /*result = max(solve(idx + 1, capacity),
            solve(idx+1,capacity-w[idx]) + v[idx]);*/
    
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    cout << solve(0, k);
}