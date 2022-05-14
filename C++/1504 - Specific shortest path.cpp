#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 2 * 1e5 + 1;
const int INF = 987654321;

priority_queue<pii> pq;	// weight, connected vertex
vector<pii> adj[MAX];
int disp[MAX];			
int n, e;				// number of vertex, number of edge
int from, to, w;		// weight btw 'from' and 'to' 
int v1,v2;				// spot v1, v2 that must pass

int dijkstra(int start, int terminal)
{
	for (int i = 0; i < MAX; i++)
		disp[i] = INF;

	// initialize
	pq = priority_queue<pii>();

	disp[start] = 0;
	pq.push({ 0,start });

	// dijkstra
	while (!pq.empty())
	{
		pii cur = pq.top(); pq.pop();

		// eliminate dummy data 
		if (disp[cur.second] != -1 * cur.first)
			continue;

		for (pii e : adj[cur.second])
		{
			int next = e.second;
			int next_disp = e.first + (-1 * cur.first);
			if (next_disp < disp[next])
			{
				disp[next] = next_disp;
				pq.push({ -1 * disp[next], next });
			}
			
		}
	}
	// shortest path to terminal
	return disp[terminal];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		cin >> from >> to >> w;
		//  since there's no direction, check adjacency
		adj[from].push_back({ w,to });
		adj[to].push_back({ w,from });
	}

	cin >> v1>>v2;

    // route 1: shortest path[(1 -> v1) + (v2 -> n)]
	int temp1 = dijkstra(1, v1) + dijkstra(v2, n);
    // route 1: shortest path[(1 -> v2) + (v1 -> n)]
	int temp2 = dijkstra(1, v2) + dijkstra(v1, n);
	// reducing from 3 INF to 2 INF
    // ans is the shortest path among 1-v1-v2-n / 1-v2-v1-n
	int ans = min(min(temp1, temp2), INF) + dijkstra(v1, v2);
	
	if (ans >= INF)
		cout << -1;
	else
		cout << ans;

	return 0;
}
