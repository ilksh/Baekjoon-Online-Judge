#include<iostream>
#include<string.h>
using namespace std;
const int MAX_N = 100;
typedef long long int lii;

int n; // length
lii dp[MAX_N][2];

 lii solve(int digit, int start)
{	
	lii& result = dp[digit][start];

	if (result != -1)
		return result;

	if (start == 1)
		result = solve(digit - 1, 0);

	else if (start == 0)
		result = solve(digit - 1, 0) + solve(digit - 1, 1);

	return result;
}
int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	dp[1][0] = 0;
	dp[1][1] = 1;
	long long int sum = solve(n, 0) + solve(n, 1);
	cout << sum;

}