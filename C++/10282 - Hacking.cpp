#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX = 1e5 + 1;
const int INF = 987654321;
typedef pair<int, int> pii;

int disp[MAX];
vector<pii> rely[MAX];	// weight, connected computer
priority_queue<pii> pq;
queue<pii> q;

int test_case;
int n, d, c;	// number of computer and dependence and hacked computer number
int a, b, s;	// if a depends on b, a will be infected in s seconds

pii dijkstra(int start)
{
	for (int i = 0; i < MAX; i++)
		disp[i] = INF;

	pq = priority_queue<pii>();

	disp[start] = 0;
	pq.push({ 0,start });

	// dijkstra
	while (!pq.empty())
	{
		pii cur = pq.top(); pq.pop();

		// removedummy data
		if (disp[cur.second] != -1 * cur.first)
			continue;

		for (pii e : rely[cur.second])
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

	pii ans; // number of infected computer, max time
	int cnt =0 , mx = -1;

	for (int i = 1; i <= n; i++)
	{	
		cout << "disp: " << disp[i] << "\n";
		if (disp[i] != INF)
		{
			cnt++;
			mx = max(mx, disp[i]);
		}
	}
	ans.first = cnt;
	ans.second = mx;

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> test_case;
	while (test_case --)
	{	
		// initialize
		for (int i = 0; i < MAX; i++)
			rely[i].clear();

		cin >> n >> d >> c;
		for (int i = 0; i < d; i++)
		{
			cin >> a >> b >> s;
            // a depends on b = if b infected, a will be infected
            // rely[a].push_back({ s,b }) = a->b (x)
            // rely[b].push_back({ s,a }) = b->a (o)
			rely[b].push_back({ s,a });
		}

		pii present = dijkstra(c);
		cout << present.first <<" "<< present.second <<"\n";
	}
}
