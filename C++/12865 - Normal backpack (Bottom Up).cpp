#include <iostream>
#include<string.h>
using namespace std;
const int MAX_N = 101;
const int MAX_K = 1e5 + 1;
int dp[MAX_N][MAX_K];
int w[MAX_N];   // weight
int v[MAX_N];   // value 
int n, k;       

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];


    for (int idx = 1; idx <= n; idx++)
    {
        for (int cap = 1; cap <= k; cap++)
        {
            dp[idx][cap] = max(dp[idx - 1][cap],
                               dp[idx][cap-1])  ;
            if (cap >= w[idx])
            {
                dp[idx][cap] = max(dp[idx][cap],
                    v[idx] + dp[idx - 1][ cap - w[idx] ]);
            }  
        }
    }

    cout << dp[n][k];
    
    /*for (int idx = 1; idx <= n; idx++)
    {
        for (int cap = 1; cap <= k; cap++)
            cout << dp[idx][cap] << " ";
        cout << "\n";
    }*/
       
        
   
}
