#include<iostream>
#include<string.h>
using namespace std;
const int MAX_N = 101;
long long int dp[MAX_N];
int t; //test case
int n;

long long int solve(int num)
{
	if (num < 1) return 0;
	if (num > 0 && num <= 3)
		return 1;

	long long int& result = dp[num];
	if (result != -1)
		return result;

	result = solve(num - 2) + solve(num - 3);
	return result;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> n;
		cout << solve(n)<<"\n";
	}
	return 0;
	
}