#include<iostream>
#include<string.h>
using namespace std;

const int INF = 1e9 + 5;
const int MAX_N = 1e6 + 1;

int cache[MAX_N];

int solve(int x) 
{	
	if (x == 1)
		return 0;

	int& ret = cache[x];

	if (ret != -1) return ret;
	
	ret = 1 + solve(x - 1);
	
	if (x % 3 == 0) ret = min(ret, 1 + solve(x / 3));
	if (x % 2 == 0) ret = min(ret, 1 + solve(x / 2));

	return ret;
}	

int main()
{
	memset(cache, -1, sizeof(cache));

	int num;
	cin >> num;
	cout << solve(num);

	return 0;
}