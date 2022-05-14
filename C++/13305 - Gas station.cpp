#include<iostream>
#include<vector>
using namespace std;
vector <long long> dist;
vector <int> oil;
int cheap_oil = 987654321;
long long int result;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	int d, o;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> d;
		dist.push_back(d);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> o;
		oil.push_back(o);

		if (oil[i] < cheap_oil)
		{
			cheap_oil = oil[i];
			result += dist[i] * cheap_oil;
		}
		else
			result += dist[i] * cheap_oil;
	}

	cout << result;
	return 0;
}

