#include<iostream>
#include<algorithm>
using namespace std;

int rope[100001];
int idx;
long long int answer;
long long int cur;

int main()
{
	int n; cin >> n;
	while (n--)
	{
		int data; cin >> data;
		rope[idx++] = -data;
	}
	sort(rope, rope + idx);
	
	for (int i = 0; i < idx; i++)
	{
		cur = (-rope[i]) * (i + 1);
		if (cur > answer)
			answer = cur;
	}
	cout << answer;
}