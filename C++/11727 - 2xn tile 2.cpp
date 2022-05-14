#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;


const int MAX_N = 1e6;
int cache[MAX_N];

int square_filling(int remain)
{
	int& result = cache[remain];

	if (remain == 1)
		return 1;

	if (remain == 2)
		return 3;

	if (result != -1)
		return result;

	result = ( square_filling(remain - 1) + (square_filling(remain - 2) *2 )) % 10007;

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(cache, -1, sizeof(cache));

	int n;
	cin >> n;
	cout << square_filling(n) % 10007;


}