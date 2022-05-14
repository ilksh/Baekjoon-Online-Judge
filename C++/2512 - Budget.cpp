#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int lli;
const int MAX_N = 1e4 + 1;
lli n;				//number of province
lli budget[MAX_N];
lli total;			//Total budget
lli summation;

bool check(lli num)
{
	lli imsi = 0;
	for (int i = 0; i < n; i++)
	{
		if (budget[i] < num)
			imsi += budget[i];
		else
			imsi += num;
	}

	if (imsi <= total)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> budget[i];
		summation += budget[i];
	}
		
	sort(budget, budget + n);

	cin >> total;

	if (summation <= total)
		cout << budget[n - 1];

	else
	{
		lli end = budget[n - 1];
		lli start = 0;
		lli mid;

		while ((end - start) > 1)
		{
			mid = (end + start) / 2;
			//cout << "mid: " << mid << "\n";

			if (check(mid))
				start = mid;
			else
				end = mid;
		}

		cout << start;
	}
	
	return 0;

}