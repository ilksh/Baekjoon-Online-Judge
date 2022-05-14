#include<iostream>
#include<string.h>
using namespace std;

const int MAX_N = 1e3 + 1;
int dp[MAX_N];
int card[MAX_N];
int n; 

//Top down
int solve(int cnt)
{
	if (cnt == 0)
		return 0;

	int& result = dp[cnt];

	if (result != -1)
		return result;

	for (int i = 1; i <= cnt; i++)
		result = max(result, card[i] + solve(cnt - i));

	return result;

}


int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> card[i];

	cout << solve(n);

}