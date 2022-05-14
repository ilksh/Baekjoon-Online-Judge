#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF = 987654321;
const int MAX_N = 1e3 + 1;
typedef pair<int, int> pii;

priority_queue<pii> pq;		//weight, next vertex
vector<pii> adj[MAX_N];
int disp[MAX_N];

int n;				//number of city
int m;				//number of bus
int from, to, w;	//weight btw from to
int start, terminal;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	for (int i = 0; i < MAX_N; i++)
		disp[i] = INF;
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> from >> to >> w;
		adj[from].push_back({ w,to });
	}

	cin >> start >> terminal;

	disp[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty())
	{
		pii cur = pq.top(); pq.pop();

		if (disp[cur.second] != -1 * cur.first)
			continue;

		for (pii e : adj[cur.second])
		{
			int next = e.second;
			int next_disp =  (- 1 * cur.first)+ e.first;

			if (next_disp < disp[next])
			{
				disp[next] = next_disp;
				pq.push({ -1 * disp[next], next });
			}
		}
	}

	cout << disp[terminal];

}