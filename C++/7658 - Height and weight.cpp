#include<iostream>
using namespace std;

const int MAX_N = 51;

int weight[MAX_N];
int height[MAX_N];
int answer[MAX_N];
int cnt;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> weight[i] >> height[i];
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (height[j] > height[i] && weight[j] > weight[i])
				cnt++;
		}
		answer[i] = cnt + 1;
		cnt = 0;
	}
	for (int i = 1; i <= n; i++)
		cout << answer[i] << " ";
}