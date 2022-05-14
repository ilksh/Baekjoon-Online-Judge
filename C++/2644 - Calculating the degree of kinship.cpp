#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int MAX_N = 101;

vector<int> v[MAX_N];	// adjacent list
bool visited[MAX_N];
queue<int> q;
int n;					
int person1, person2;	
int m;					
bool success;			

int kinship(int solve, int destination)
{
	int cnt = 0;
	q.push(solve);
	visited[solve] = true;

	while (!q.empty())
	{
		int qSz = q.size();
		for (int iter = 0; iter < qSz; iter++)
		{
			int cur = q.front(); q.pop();
			if (cur == destination)
				return cnt;

			for (int i = 0; i < v[cur].size(); i++)
			{
				int imsi = v[cur][i];
				if (!visited[imsi])
				{
					q.push(imsi);
					visited[imsi] = true;
				}
			}
		}
		cnt++;
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> person1 >> person2;			
	cin >> m;

	while (m--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	cout << kinship(person1,person2);

	return 0;
}