#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int lli;
const int MAX_N = 1e5 + 1;
lli n;	// size of array
lli k;  // target index

bool check(lli num)
{
	lli cnt = 0; // number of numbers which is smaller than num (median) in i * j array
	for (int i = 1; i <= n; i++)
	{
        // number of case, which is smaller than num and n%i ==0, is num/i
		cnt += min(num / i, n);
	}
		
	if (cnt >= k)
		return true;

	return false;

}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	cin >> k;

	k = min(lli(1e9), k);
	lli start = 1;
	lli end = n * n;
	lli mid;

	while ((end - start) >= 0)
	{
		mid = (start + end) / 2;

		if (check(mid))
			end = mid-1;
		else
			start= mid+1;
	}

	cout << start;

	return 0;
}