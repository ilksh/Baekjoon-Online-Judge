#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int lli;

const int MAX_K = 1e4 + 1;
lli k; 
lli n; 
lli internet[MAX_K];

bool check(lli num)
{
	lli cnt = 0;

	for (int i = 0; i < k; i++)
	{
		int cur = internet[i];

		while (cur >= num)
		{
			cur -= num;
			cnt++;
		}
	}

	if (cnt >= n)
		return true;

	return false;
}


int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> k >> n;
	lli end = -1;

	for (int i = 0; i < k; i++)
	{
		cin >> internet[i];
		end = max(end, internet[i]);
	}

	end += 1;
	lli start = 1;
	lli mid;

	while ((end - start) > 1)
	{
		mid = (end + start) / 2;

		if (check(mid))
			start = mid;
		else
			end = mid;
	}

	cout << start;
		
	return 0;
	
}