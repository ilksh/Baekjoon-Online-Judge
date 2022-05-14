#include<iostream>
#include<string.h>
using namespace std;
const int MAX_N = 100;
int cache[MAX_N];

int fib(int x)
{	
	int& result = cache[x];

	if (x == 0)
		return 0;

	if (x == 1)
		return 1;
		
	if (result != -1)
		return result;
	
	result = fib(x - 1) + fib(x - 2);
	return result;
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));

	int num;
	cin >> num;
	cout << fib(num);
		
	return 0;
}
