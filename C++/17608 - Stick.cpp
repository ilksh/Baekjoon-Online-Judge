#include<iostream>
#include<stack>
using namespace std;

stack<int> s;
int MAX;

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	while (n--)
	{
		int stick;
		cin >> stick;
		s.push(stick);
	}

	int standard = s.top(); s.pop();
	MAX = standard;
	int cnt = 1;

	while (!s.empty())
	{
		int cur = s.top(); s.pop();

		if (cur > standard)
		{
			if (cur > MAX)
				cnt++;
		}

		if (cur > MAX)
			MAX = cur;
	}
	cout << cnt;

}