#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
const int MAX_EDGE = 2701;
const int MAX_N = 505;
const long long INF = 3e18;
typedef pair <int, int> pii;

int test_case;
int n, m, hole;					
int u, v, w;					
long long dist[MAX_N];
bool visited[MAX_N];				// visitied = dfs implemenation method
vector <pii> adj[MAX_N];			// Adgacent-list
vector <int> start_component;
queue <string> ans;

bool bellman_ford(int start)
{
	bool isCycle = false;
	dist[start] = 0;

	for (int round = 1; round <= n; round++)
	{
		bool relax = false;

		// Adjacent-list method = visit all vertices
		for (int i = 1; i <= n; i++)
		{
            // search all vertices that connected with current vertex
			for (auto e : adj[i])
			{
				int next = e.second;
				int next_dist = dist[i] + e.first;

				if (next_dist < dist[next])
				{
					relax = true;
					dist[next] = next_dist;
				}
			}
		}
        // if 'relaxing' working, after several rounds == negative cycle
		if (round == n && relax)
			isCycle = true;
	}

	return isCycle;
}

void dfs(int num)
{
	visited[num] = true;

	for (auto e : adj[num])
	{
		int next = e.second;
		if (!visited[next])
		{
			dfs(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> test_case;

	while (test_case--)
	{

		// initialize adjacent list and dist
		for (int i = 0; i < MAX_N; i++)
		{
			adj[i].clear();
			dist[i] = INF;
		}

		// initialize start comopent 
		start_component.clear();

		// initialize visited 
		memset(visited, 0, sizeof(visited));

		cin >> n >> m >> hole;

		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			adj[u].push_back({ w,v });
			adj[v].push_back({ w,u });
		}

		//worm hole
		for (int i = m; i < m + hole; i++)
		{
			cin >> u >> v >> w;
			adj[u].push_back({ -w,v });
		}

		// check start component
		for (int i = 1; i <= n; i++)
		{   
            // not visited = start of one component
			if (!visited[i])
			{
				start_component.push_back(i);
                // check component through dfs
				dfs(i);
			}
		}

		bool isCycle = false;
		for (auto e : start_component) {
			isCycle |= bellman_ford(e);
		}

		// icCycle = true -> YES, false ->  NO
		cout << (isCycle ? "YES" : "NO") << '\n';

	return 0;
}