#include<iostream>
#include<string.h>
using namespace std;
const int MAX_N = 1e6 + 1;
int n;
int dp[MAX_N];

//Top Down
int solve(int num)
{	
	if (num == 1)
		return 1;
	if (num == 2)
		return 2;

	int& result = dp[num];
	if (result != -1)
		return result;
	result = (solve(num - 1) + solve(num - 2)) % 15746;
	return result;
}


int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	cout << solve(n);

	/*
    Bottom Up method

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n];
	*/

}
