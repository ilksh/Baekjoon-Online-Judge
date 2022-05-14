#include<iostream>
#include<string.h>
using namespace std;

const int MAX_N = 501;
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int n; 

int solve(int row, int col)
{	
	if (row > n && col > n)
		return 0;
		
	int& result = dp[row][col];

	if (result != -1) return result;

	result = max(solve(row + 1, col), solve(row + 1, col + 1)) + arr[row][col];

	return result;
}

int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i + 1; j++)
			cin >> arr[i][j];
	}

	cout << solve(1, 1);
}