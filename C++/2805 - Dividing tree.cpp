#include<iostream>
using namespace std;

const int MAX_N = 1e6 + 1;
int n; // number of tree
int m; // length of tree I am trying to take
typedef long long int lli;

lli tree[MAX_N];

bool check(lli num)
{
	lli rst = 0;
	for (int i = 0; i < n; i++)
	{
		if (tree[i] > num)
			rst += (tree[i] - num);
	}

	if (rst >= m)
		return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	lli end = -1;

	for (int i = 0; i < n; i++)
	{
		cin >> tree[i];
		end = max(end, tree[i]);
	}
	end += 1;
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