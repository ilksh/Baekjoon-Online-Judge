#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (num < 2)
			continue;

		cnt++;
		for (int j = 2; j < num; j++)
		{
			if (num % j == 0)
			{
				cnt--;
				break;
			}
		}
	}

	cout << cnt;

	return 0;
}
