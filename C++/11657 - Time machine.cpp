#include<iostream>
#include<vector>
using namespace std;
const int MAX_EDGE = 6001;
const long long INF = 3e9;

struct Edge {
	int u, v, w;
};
Edge edges[MAX_EDGE];

long long dist[505];
int n, m;	

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	for (int i = 2; i < MAX_EDGE; i++)
		dist[i] = INF;

	dist[1] = 0;

	// Input data
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> edges[i].u >> edges[i].v >> edges[i].w;

	// Initial = negative cycle occurs
	bool isCycle = false;

	for (int i = 0; i < n; i++)
	{
		bool relax = false;

		for (int j = 0; j < m; j++)
		{
			Edge e = edges[j];

			if (dist[e.u] == INF)
				continue;

			if (dist[e.u] + e.w < dist[e.v])
			{
				relax = true;
				dist[e.v] = dist[e.u] + e.w;
			}

		}

		if (i == n - 1 && relax)
			isCycle = true;
	}

	if (isCycle)
		cout << -1 << "\n";
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (dist[i] == INF)
				cout << -1 << "\n";
			else
				cout << dist[i] << "\n";
		}
	}

	return 0;
}
