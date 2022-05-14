#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
queue<int> q;
int remain;
int cnt;
int bills[4] = { 25,10,5,1 };
int answer[4];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{	
		memset(answer, 0, sizeof(answer));

		int change;
		cin >> change;
		for (int j = 0; j < 4; j++)
		{
			if (change >= bills[j])
			{
				answer[j] = change / bills[j];
				change = change % bills[j];
			}
		}
		for (int j = 0; j < 4; j++)
			cout << answer[j] << " ";
		cout << "\n";
	}

}