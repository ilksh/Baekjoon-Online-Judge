#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

const int MAX_N = 1e5 + 1;
int dp[2][MAX_N];
int test_case;
int sticker[2][MAX_N];
int n;

int solve(bool row, int col)
{	 
	if (col > n)
		return -987654321;

	if (col == n)
		return sticker[row][col];

	int& result = dp[row][col];

	if (result != -1)
		return result;

	result = sticker[row][col] +
		max(solve(!row, col + 1), max(solve(row, col + 2), solve(!row, col + 2)));
	return result;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> test_case;
	while (test_case--)
	{	
		memset(dp, -1, sizeof(dp)); 

		cin >> n;
		for (int i = 0; i <= 1; i++)
			for (int j = 1; j <= n; j++)
				cin >> sticker[i][j];

		int temp1 = solve(0, 1);
		int temp2 = solve(1, 1);

		int ans = max(temp1, temp2);
		cout << ans<<"\n";
	}
}
