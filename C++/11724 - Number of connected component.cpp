#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 1e3 + 1;

vector<int> adj[MAX];
bool visited[MAX];
int n, m;	

void dfs(int num)
{
	visited[num] = true;
	for (auto e : adj[num])
	{
		if (!visited[e])
			dfs(e);
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int component = 0;

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			component++;
			dfs(i);
		}
	}
	cout << component;
	return 0; 
}