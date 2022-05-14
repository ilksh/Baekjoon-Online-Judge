#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int lli;
const int MAX_N = 2 * (1e5) + 1;
int n;		  //number of house
int router;   //number of router
lli x[MAX_N]; 

bool check(lli num)
{	
	int cnt = 1;
	lli past = x[0];
	for (int idx = 1; idx < n; idx++)
	{
		lli cur = x[idx];

		if ((cur - past) >= num)
		{
			cnt++;
			past = cur;
		}
	}

	if (cnt >= router)
		return true;
	return false;
}

int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> router;
	
	for (int i = 0; i < n; i++)
		cin >> x[i];

	sort(x, x + n);

	lli end = x[n - 1] - x[0]+1;
	lli start = 0;
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