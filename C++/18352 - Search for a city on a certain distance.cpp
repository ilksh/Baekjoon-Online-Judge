#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 1e6 + 1;
const int INF = 987654321;
typedef pair<int, int> pii;

vector<int> adj[MAX];
priority_queue<int> pq;
priority_queue<int> ans;

int n, m, k, x;				// number of city (n) and road (m), distance (k), start (x)
int dist[MAX];
int from, to;

void ans_print()
{
	while (!ans.empty())
	{
		int a = -1 * ans.top(); ans.pop();
		cout << a << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	// initialize
	for (int i = 0; i < MAX; i++)
		dist[i] = INF;

	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++)
	{
		cin >> from >> to;
		adj[from].push_back({ to });
	}

	dist[x] = 0;
	pq.push(x);

	while (!pq.empty())
	{
		int cur = pq.top(); pq.pop();

		for (int e : adj[cur])
		{
			int next = e;
			int next_dist = dist[cur] + 1;

			if (next_dist < dist[next])
			{
				dist[next] = next_dist;
				pq.push(next);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{	
		//cout << "dist: " << dist[i] << "\n";

		if (dist[i] == k)
			ans.push(-i);
	
	}

	if (ans.empty())
		cout << -1;
	else
		ans_print();

	return 0;

}