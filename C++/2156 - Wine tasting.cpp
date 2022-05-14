#include<iostream>
#include<string.h>
using namespace std;
const int MAX_SIZE = 1e4 + 1;
int n;							//number of goblet
int wine[MAX_SIZE];
int dp[MAX_SIZE];
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> wine[i];
	
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int idx = 3; idx <= n; idx++)
	{	
			int result_1 = dp[idx - 3] + wine[idx - 1] + wine[idx];
			int result_2 = dp[idx - 2] + wine[idx];
			dp[idx] = max(result_1, result_2);
			dp[idx] = max(dp[idx], dp[idx - 1]);
		
	}

	cout << dp[n];

}