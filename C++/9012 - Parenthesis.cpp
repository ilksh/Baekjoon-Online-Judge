#include<iostream>
#include<queue>
using namespace std;
char mark[51];
queue<int> answer;
int cnt;

int main()
{	
	int num;
	cin >> num;
	for (int j = 0; j < num; j++)
	{
		cin >> mark;
		for (int i = 0; i < 51; i++)
		{
			if (mark[i] != '\0')
			{
				if (mark[i] == '(')
					cnt++;
				else if (mark[i] == ')' && cnt >0)
					cnt--;
				else if (mark[i] == ')' && cnt <= 0)
				{
					cnt--;
					i = 51;
				}
			}

			if (mark[i] == '\0')
				i = 51;
		}
		if (cnt == 0)
			answer.push(1);
		if (cnt != 0)
			answer.push(0);
		cnt = 0;
	}

	while (!answer.empty())
	{
		int cur = answer.front(); answer.pop();
		if (cur == 1)
			cout << "YES" << "\n";
		if (cur == 0)
			cout << "NO" << "\n";
	}

}
