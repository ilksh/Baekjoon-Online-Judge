#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N = 5 * 1e3 + 1;

int n; 
int m; 
int num[MAX_N];
int diff;

bool check(int mid)
{
	int local_min = num[0];
	int local_max = num[0];
	int cnt = 1;

	for (int idx = 1; idx < n; idx++)
	{
		local_min = min(local_min, num[idx]);
		local_max = max(local_max, num[idx]);
		diff = local_max - local_min;

		if (diff > mid)
		{
			cnt++;
			local_min = num[idx];
			local_max = num[idx];
		}
	}
	if (cnt <= m)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int mx = -1;		//max

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		mx = max(mx, num[i]);
	}

	int start = -1; // don't include start
	int end = mx+1;
	int mid;
	while ((end - start) > 1)
	{
		mid = (end + start) / 2;

		if (check(mid))
			end = mid;
		else
			start = mid;
	}

	cout << end;
	return 0;
}
