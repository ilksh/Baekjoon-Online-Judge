#include<iostream>
#include<string.h>
using namespace std;

const int MAX_N = 1e3 + 1;
int dp[MAX_N];
int card[MAX_N];
int n; 

//Bottom-Up
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> card[i];

	dp[1] = card[1];
	for (int idx = 2; idx <= n; idx++)
	{
		for (int j = 1; j <= idx; j++)
		{
			dp[idx] = max(dp[idx-j]+card[j],dp[idx]);
		}
	}

	cout << dp[n];
}