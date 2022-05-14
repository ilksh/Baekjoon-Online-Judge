#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
const int MAX_N = 1e3 + 1;
const int INF = 987654321;

int paint[MAX_N][3];
int cache[MAX_N][3][3];
int n; //number of house
priority_queue <int> ans;

int solve(int y, int x, int ix)
{	
	if (y == n - 1)		//last
		return ix == x ? INF : paint[y][x];

	int& result = cache[y][x][ix];

	if (result != -1) return result;

	if (x == 0)
		result = min(solve(y + 1, x + 1,ix), solve(y + 1, x + 2,ix) ) + paint[y][x];

	if (x == 1)
		result = min(solve(y + 1, x - 1,ix), solve(y + 1, x + 1,ix)) + paint[y][x];

	if (x == 2)
		result = min(solve(y + 1, x - 1,ix), solve(y + 1, x -2,ix )) + paint[y][x];
	
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> paint[i][j];
	}
	
	for (int i = 0; i < 3; i++)
	{
		int data = solve(0, i,i);
		ans.push(-data);
	}

	cout << -ans.top();
	return 0;
}