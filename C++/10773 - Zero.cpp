#include<iostream>
#include<stack>

using namespace std;
stack<int> s;
int result;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;
		if (data != 0)
			s.push(data);
		if (data == 0)
			s.pop();
	}

	while (!s.empty())
	{	
		result += s.top();
		s.pop();
	}
	cout << result;
}