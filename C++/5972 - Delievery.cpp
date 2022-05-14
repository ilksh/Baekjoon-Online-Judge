#include<iostream>
#include<vector>
#include<queue>
#define MAX 50001
using namespace std;
typedef pair<int, int> pii;

const int INF = 987654321;
vector<pii> adj[MAX];
priority_queue<pii> pq;
int dist[MAX];
int n, m; // map, road
int from, to, w;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	for (int i = 0; i < MAX; i++)
		dist[i] = INF;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> from >> to >> w;
		adj[from].push_back({ w,to });
		adj[to].push_back({ w,from });
	}

	pq.push({ 0,1 });
	dist[1] = 0;

	while (!pq.empty())
	{
		pii cur = pq.top(); pq.pop();

		if (dist[cur.second] != -1 * cur.first)
			continue;

		for (pii e : adj[cur.second])
		{
			int next = e.second;
			int next_disp = e.first + (-1) * cur.first;

			if (next_disp < dist[next])
			{
				dist[next] = next_disp;
				pq.push({ -1 * dist[next], next });
			}
		}
	}

	cout << dist[n];
}