#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
priority_queue <int> pq;

const int MAX_N = 1e5 + 5;
long long int sum;
char str[MAX_N];
int n, len;
int cnt;

int main()
{
	cin >> str;
	len = strlen(str);
	for (int i = 0; i < len; ++i) {
		int data = (str[i]-'0') % 10;
		if (data == 0)
			cnt++;
		sum += data;
		pq.push(data);
	}

	if (cnt == 0 || sum % 3 != 0)
		cout << "-1";
	if (cnt != 0 && sum % 3 == 0)
	{
		while (!pq.empty())
		{
			int cur = pq.top(); pq.pop();
			cout << cur;
		}
	}

}