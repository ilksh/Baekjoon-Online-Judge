#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int, pii> ipii;   // position, {cost, dist}

vector<ipii> adj[102];       // position, {cost, dist}
priority_queue<ipii> pq;     // dist, {position, cost}

const int INF = 1e9;
const int MAX_N = 1e2 + 2;  // max # of node
const int MAX_M = 1e4 + 4;  // max budget
const int MAX_K = 1e4 + 4;  // max # of edge

// n : # of airport (node), m : budget, k = # of ticket (edge)
int n, m, k;

// u : start, v : arriaval, c = cost, d = time spent
int u, v, c, d;

// row = node, col = cost
// shortest path from start point to index of row with the cost of col
int rst[MAX_N][MAX_K];

void ansPrint()
{
    int mn = INF;
    for(auto e:rst[n]) mn = min(mn, e);

    
    // unable to arrive to the destination
    if (mn == INF) cout << "Poor KCM\n";
    else cout << mn << "\n";
}

void dijstra()
{
    // initialize
    for(int i = 0 ; i <= n ;++i) {
        for(int j = 0 ; j < MAX_M; ++j)
            rst[i][j] = INF;
    }
    
    pq.push({0, {1,0}});
    rst[1][0] = 0;
    
    while(!pq.empty())
    {
        // pq = {dist, {position, cost}}
        auto cur = pq.top(); pq.pop();
        int curDist = -cur.first;
        int curPos = cur.second.first;
        int curCost = cur.second.second;
        
        if(rst[curPos][curCost] < curDist)
            continue;;
        
        // searching all adjacent nodes
        for(auto e: adj[curPos])
        {
            // adj = {position, {cost, dist}}
            int nextPos = e.first;
            int nextCost = curCost + e.second.first;
            int nextDist = curDist + e.second.second;
            
            if(nextCost > m) continue;  // optimization
            
            // update information
            if(rst[nextPos][nextCost] > nextDist)
            {
                rst[nextPos][nextCost] = nextDist;
                pq.push({-nextDist, {nextPos, nextCost}}); // {dist, {position, cost}}
            }
            
        }
    }
    ansPrint();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    
    while(tc--)
    {
        cin >> n >> m >> k;
        for(int i = 0 ; i < k; ++i)
        {
            cin >> u >> v >> c >> d;
            adj[u].push_back({v, {c,d}});
        }
        
        dijstra();
        
        // reset variables for next testcase
        for(int i = 0; i < MAX_N; ++i) adj[i].clear();
        while(!pq.empty()) pq.pop();
    }
    return 0;
}
