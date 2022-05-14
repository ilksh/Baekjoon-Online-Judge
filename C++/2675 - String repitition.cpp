#include<iostream>
#include<string>
#include<queue>
using namespace std;

queue<char> q;
queue<char> ans;
string s;
int r; 

void solve(int r, char cur)
{
	for (int i = 0; i < r; i++)
		ans.push(cur);
	return;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int test_case;
	cin >> test_case;
	while (test_case--)
	{
		cin >> r;
		cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			char cur = s[i];
			solve(r, cur);
		}
		while (!ans.empty())
		{
			char top = ans.front(); ans.pop();
			cout << top;
		}
		cout << "\n";
	}


}

