#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> pq;

int main()
{	
	int coin_type, money;
	cin >> coin_type >> money;

	for (int i = 0; i < coin_type; i++)
	{
		int c; cin >> c;
		pq.push(c);
	}

	int result = 0;

	while (!pq.empty())
	{
		int cur = pq.top(); pq.pop();
		if (money >= cur)
		{
			result += (money / cur);
			money = money % cur;
		}
	}
	cout << result;

}