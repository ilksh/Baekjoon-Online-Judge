#include<iostream>
#include<string.h>
using namespace std;
const int MAX_k = 1e3 + 1;
const int MAX_t = 1e4 + 1;
int i[MAX_k]; //importance
int t[MAX_k]; //time of study
int dp[MAX_k][MAX_t];
int n; // max study time
int k; // number of subject

int solve(int subject, int MAXTime)
{
	if (subject == k)
		return 0;
	int& result = dp[subject][MAXTime];

	if (result != -1)
		return result;

	result = solve(subject + 1, MAXTime);
	if (MAXTime >= t[subject])
	{
		result = max(result,
			solve(subject + 1, MAXTime - t[subject]) + i[subject]);
	}
	return result;
}


int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof(dp));
	
	cin >> n >> k;
	for (int iter = 0; iter < k; iter++)
		cin >> i[iter] >> t[iter];

	cout << solve(0, n);

}