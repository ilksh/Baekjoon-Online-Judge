#include<iostream>
#include<string.h>
using namespace std;
const int MAX_N = 1e5 + 5;
int n;
int a[MAX_N];
int dp[MAX_N];

int main()
{	
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int ans = a[1];
	int sum = a[1];

	for (int i = 2; i <= n; i++)
	{
		if (sum < 0)
			sum = 0;

		sum += a[i];

		if (sum >= ans)
			ans = sum;

		
	}
	
	cout << ans;

	
}