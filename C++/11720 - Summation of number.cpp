#include<iostream>
#include<string.h>
using namespace std;

string s;
int result;

int main()
{
	int n;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		int cur = s[i] - '0';
		result += cur;
	}
	cout << result;
}