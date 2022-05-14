#include<iostream>
#include<queue>
using namespace std;

priority_queue <int> pq;
queue<int> answer;

int main()
{
	int n; cin >> n;
	while (n--)
	{
		int order;
		cin >> order;

		if (order == 0)
		{
			if (pq.empty())
				answer.push(0);
			if (!pq.empty())
			{
				int cur = pq.top();
				pq.pop();
				answer.push(cur);
			}
		}
		else
			pq.push(order);
	}
	
	while (!answer.empty())
	{
		cout << answer.front() << "\n";
		answer.pop();
	}
}