#include<iostream>
using namespace std;
typedef long long int lli;
int n, m;
lli combination[31][31];

lli calc(int n, int r)
{
	int d1 = n - r;

	if (d1 < r)
	{
		int temp = d1;
		d1 = r;
		r = temp;
	}

	lli numerator = 1;
	for (int i = n; i > d1; i--)
		numerator *= i;

	lli denominator = 1;

	for (int i = 2; i <= r; i++)
		denominator *= i;

	lli ans = numerator / denominator;
	return ans;
}

void filling()
{
	for (int i = 1; i <= 30; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i == j)
				combination[i][j] = 1;
			else if (j == 1)
				combination[i][j] = i;
			else
			{
				combination[i][j] = calc(i, j);
			}
		}
	}
	
}


int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int test_case;
	cin >> test_case;
	filling();
	while (test_case--)
	{
		cin >> n >> m;
		cout << combination[m][n] << "\n";
	}
}