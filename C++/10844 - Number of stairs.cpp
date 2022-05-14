#include<iostream>
#include<string.h>
using namespace std;
const int MAX_N = 105;

int n; //length
int dp[MAX_N][10];

int solve(int digit, int start)
{	

	int& result = dp[digit][start];
	if (result != -1) return result;

	result = 0;

	if (start == 0)
		result += solve(digit - 1, start + 1);
	else if (start == 9)
		result += solve(digit - 1, start - 1);
	else
		result += (solve(digit - 1, start + 1) + solve(digit - 1, start - 1)) ;
	
	return result %= 1000000000;

}
int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> n;

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 0; i <= 9; i++)
		solve(n, i);

	long long int sum = 0;

	for (int i = 1; i <= 9; i++) {
		sum += dp[n][i];
		sum %= 1000000000;
	}

	cout << sum;
}