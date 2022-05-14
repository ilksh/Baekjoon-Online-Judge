#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int lli;
const int MAX_SIZE = 1e6 + 1;
int m; 
int n;
int length[MAX_SIZE];

bool check(int num)
{
	lli cnt = 0;

	for (int i = 0; i < n; i++)
	{
		cnt += length[i] / num;
	
	}
	/*cout << "cnt: " << cnt << "\n";
	cout << "========\n";*/

	if (cnt >= m)
		return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> m >> n;
	int mx = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> length[i];
		mx = max(mx, length[i]);
	}

	int start = 0;
	int mid;
	int end = mx+1;

	while ((end - start) > 1)
	{
		mid = (end + start) / 2;

		/*cout << "start: " << start << "\n";
		cout << "mid: " << mid << "\n";
		cout << "end: " << end << "\n";*/

		if (check(mid))
			start = mid;

		else
			end = mid;
	}

	cout << start;
	return 0;
}