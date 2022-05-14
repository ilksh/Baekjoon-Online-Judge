#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
const int MAX_EDGE = 2501;
const long long INF = 3e9;

queue<string> ans;

struct Edge {
	int u, v, w;
};
Edge edges[MAX_EDGE];

int test_case;
int n, m, hole;	
long long dist[505];


int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> test_case;

	while (test_case--)
	{	
		cin >> n >> m >> hole;

		for (int i = 0; i < m; i++)
			cin >> edges[i].u >> edges[i].v >> edges[i].w;

		for (int i = m; i < m + hole; i++)
		{
			cin >> edges[i].u >> edges[i].v >> edges[i].w;
			edges[i].w *= -1;
		}

		for (int i =2; i <= n; i++)
			dist[i] = INF;
		
		bool isCycle = false;

		for (int i = 0; i < n; i++)
		{
			bool relax = false;

			for (int j = 0; j < m+hole; j++)
			{
				Edge e = edges[j];

				if (dist[e.u] == INF)
					continue;
				
				if (dist[e.u] + e.w < dist[e.v])
				{
					relax = true;
					dist[e.v] = dist[e.u] + e.w;
				}

				if (e.w < 0 && dist[e.v] == INF)
					continue;
			
				if (dist[e.v] + e.w < dist[e.u])
				{
					relax = true;
					dist[e.u] = dist[e.v] + e.w;
				}
			}

			if (i == n - 1 && relax)
				isCycle = true;
		}

		if (isCycle)
			ans.push("YES");
		else
			ans.push("NO");

		for (int i = 1; i <=n; i++)
			cout << dist[i] << "\n";

		cout << "====\n";
	}

	while (!ans.empty())
	{
		string cur = ans.front(); ans.pop();
		cout << cur << "\n";
	}
}