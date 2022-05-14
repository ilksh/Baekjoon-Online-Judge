#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> a;
priority_queue<int> b;
int n,num,result;

int main()
{
	cin >> n;

	int m = n;

	while (n--)
	{ 
		cin >> num;
		a.push(-num);
	}
	while (m--)
	{
		cin >> num;
		b.push(num);
	}
	while (!a.empty() && !b.empty())
	{
		result += (-a.top()) * (b.top());
		a.pop();
		b.pop();
	}
	cout << result;
}
