#include<iostream>

using namespace std;

int main()
{
	int n;
	int result = 0;
	cin >> n;
	while (n >= 0)
	{
		if (n % 5 == 0)
		{
			result += (n / 5);
			cout << result;
			return 0;
		}
		n -= 3;
		result++;
	}
	cout << -1 << endl;
	return 0;
}
