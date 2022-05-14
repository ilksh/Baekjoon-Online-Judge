#include<iostream>
using namespace std;
const int MAX_SIZE = 1e4 + 1;
int stair[MAX_SIZE];
int dp[MAX_SIZE];

int main()
{
	int n; 
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> stair[i];

	dp[1] = stair[1];
	dp[2] = stair[1] +stair[2];

	for (int idx = 3; idx <= n; idx++)
	{
			int r1 = dp[idx - 3] + stair[idx - 1] + stair[idx];
			int r2 = dp[idx - 2] + stair[idx];
			dp[idx] = max(r1, r2);
	
	}

	cout << dp[n];


}