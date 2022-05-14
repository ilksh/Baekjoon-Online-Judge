#include<iostream>
#include<string.h>
using namespace std;

const int MAX_N = 11;
int cache[MAX_N];
int n;

int calc_num(int x)
{	
	if (x == 0 )
		return 1;
	
	int& result = cache[x];

	if (result != -1) return result;

	result = 0;

	if (x >= 3)
		result += calc_num(x - 3);
	if (x >= 2)
		result += calc_num(x - 2);
	if (x >= 1)
		result += calc_num(x - 1);

	return result;
}
int main()
{
	memset(cache, -1, sizeof(cache));
	int t;
	cin >> t;

	while(t--)
	{
		cin >> n;
		cout << calc_num(n) << "\n";
	}
}