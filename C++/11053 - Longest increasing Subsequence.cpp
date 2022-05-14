#include<iostream>
#include<string.h>
using namespace std;
const int MAX_N = 1e3 + 1;
int dp[MAX_N];
int arr[MAX_N];
int n; 

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
			
		}
	}

	/*for (int i = 1; i <= n; i++)
		cout << dp[i] << "\n";*/

	int result = dp[1];
	for (int i = 2; i <= n; i++)
	{
		result = max(result, dp[i]);
	}

	cout << result;

	return 0;
}

