#include<iostream>
#include<string.h>
using namespace std;

string s;
bool check[27];
int ans[27];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(ans, -1, sizeof(ans));

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		int data = s[i] - '0';
		data -= 49;
		if (!check[data])
		{
			check[data] = true;
			ans[data] = i;
		}
	}

	for (int i = 0; i < 26; i++)
		cout << ans[i] << " ";
}