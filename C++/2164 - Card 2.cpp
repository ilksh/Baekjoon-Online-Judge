#include<iostream>
#include<queue>
using namespace std;

queue<int> q;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		q.push(i);

	while (q.size() > 1)
	{
		q.pop();
		int cur = q.front(); q.pop();
		q.push(cur);
	}
	cout << q.front() << endl;
	return 0;
}