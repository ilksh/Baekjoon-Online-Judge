#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int, int> pii;
const int INF = 987654321;
const int MAX_V = 2 * 1e4 + 1;

priority_queue<pii> pq;	// weight, connected vertec
vector<pii> adj[MAX_V];

int disp[MAX_V];		// minmum cost to nth vertex
int v,e;				// number of vertex and edge
int start;				// start
int from, to, w;		// weight btw from and to

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	// initial cost = INF
	for (int i = 0; i < MAX_V; i++)
		disp[i] = INF;
	
	cin >> v >> e;
	cin >> start;

	disp[start] = 0;		// weight of start vertex is 0
	pq.push({ 0,start });	// start search 

	for (int i = 0; i < e; i++)
	{
		cin >> from >> to >> w;
		adj[from].push_back({ w,to }); // check adjacency and the weight
	}

	while (!pq.empty())
	{	
		pii cur = pq.top(); pq.pop(); // current searching vertex

        // compare cur.first (current weight) and
        // disp (weight) up to the cur.second (connected vertex)
		// dummy data (remove the greater value)
		if (disp[cur.second] != -1 * cur.first)
			continue;

		// check all adjacent vertices from the current vertex
		for (pii e : adj[cur.second])
		{	
			int next = e.second;                         // connected next vertex
			int next_disp = (- 1 * cur.first) + e.first; // weight of next vertex = cur + next
			
            // if the current weight is lower that the weight of next vertex
			// renew with new info (add next search info)
			if (next_disp < disp[next])
			{
				disp[next] = next_disp;
				pq.push({ -1 * disp[next], next });
			}
		}

	}

	for (int i = 1; i <= v; i++)
	{
		if (disp[i] == INF)
			cout << "INF\n";
		else
			cout << disp[i] << "\n";
	}

}