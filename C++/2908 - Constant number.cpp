#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

string s1;
string s2;

int solve(string s)
{	
	int num = 0;
	int idx = 0;

	for (int i =0; i< s.size(); i++)
	{	
		int imsi = s[i] - '0';

		num += ( pow(10, idx) * imsi );
		idx++;
	}

	return num;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s1 >> s2;

	int result = max(solve(s1), solve(s2));
	cout << result;
	return 0;
	
}