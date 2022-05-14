#include<iostream>
#include<string.h>
using namespace std;
const int MAX_N = 1e3 + 1;
int dp[MAX_N][MAX_N];
string str1;
string str2;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> str1;
	cin >> str2;

	str1 = 'a' + str1;
	str2 = 'a' + str2;

	int size1 = str1.size()-1; 
	int size2 = str2.size()-1;
	
	for (int i = 1; i <= size1; i++)
	{
		for (int j = 1; j <= size2; j++)
		{
			if (str1[i] == str2[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[size1][size2];
}
// ACAYKP CAPCAK