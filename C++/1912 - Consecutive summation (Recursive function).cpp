#include<iostream>
#include<string.h>
using namespace std;
const int MAX_N = 1e5 + 5;
int n;
int arr[MAX_N];
int dp[MAX_N];

int solve(int idx)
{

	dp[idx] = max(arr[idx], dp[idx + 1] + arr[idx]);

	return dp[idx];
}


int main()
{	
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int result = -987654321;

	for (int i = n; i >= 1; i--)
		result = max(result, solve(i));

	cout <<  result;

	/*for (int i = 1; i <= n; i++)
		cout << dp[i] << " ";*/
	
}