#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
stack<int> s;
string str;

int main()
{
	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		cin >> str;
		if (str == "push")
		{
			int num;
			cin >> num;
			s.push(num);
		}
		
		if (str == "pop")
		{
			if (s.empty())
				cout << "-1\n";
			else
			{
				int cur = s.top();
				s.pop();
				cout << cur << "\n";
			}
		}
		if (str == "size")
			cout << s.size() << "\n";

		if (str == "empty")
		{
			if (s.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}

		if (str == "top")
		{
			if (s.empty())
				cout << "-1\n";
			else
				cout << s.top() << "\n";
		}

	}
}