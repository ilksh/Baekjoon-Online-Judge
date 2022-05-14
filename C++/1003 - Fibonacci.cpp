#include<iostream>
#include<string.h>
using namespace std;
const int MAX_N = 100;

int cache[MAX_N];
int zero_counting[MAX_N];
int one_counting[MAX_N];

int fib(int x)
{	
	int& result = cache[x];

	if (x == 0)
	{
		zero_counting[0] = 1;
		return 0;
	}

	if (x == 1)
	{
		one_counting[1] = 1;
		return 1;
	}
		
	if (result != -1)
		return result;
	
	result = fib(x - 1) + fib(x - 2);
	one_counting[x] = one_counting[x - 1] + one_counting[x - 2];
	zero_counting[x] = zero_counting[x - 1] + zero_counting[x - 2];

	return result;
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));
	int T; // Testcase
	cin >> T;

	while (T--)
	{
		int num;
		cin >> num;
		fib(num);
		cout << zero_counting[num] << " "<< one_counting[num] << "\n";

		memset(cache, -1, sizeof(cache));
		memset(zero_counting, 0, sizeof(zero_counting));
		memset(one_counting, 0, sizeof(one_counting));
	}
	return 0;
}
