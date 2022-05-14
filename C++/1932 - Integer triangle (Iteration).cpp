#include<iostream>
#include<string.h>
using namespace std;

const int MAX_N = 501;
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int n;

int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i + 1; j++)
			cin >> arr[i][j];
	}
    
	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
		}
	}
	
	int result = 0;
	for (int idx = 1; idx <= n; idx++)
	{
		result = max(result, dp[n][idx]);
	}

	cout << result;

}