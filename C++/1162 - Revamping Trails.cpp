#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e4 + 4;

typedef pair<int, int> pii;     // {cost, position}
typedef long long int ll;
typedef pair<ll, pii> llpii;    // {cost, {# of paved road, position}}

vector<pii> adj[MAX_N];
priority_queue<llpii> pq;       //[Node][# of trails]
ll dp[MAX_N][21];
int n, m, k;    // n: # of city (node), m: # of road(edge), k: # of trails to turn into highways,
int u, v, w;    // u, v: node, w: weight btw u, v

ll findMin()
{
    ll mn = dp[n][0];
    
    for(int i = 1; i < k + 1; ++i)
    {
        ll cur = dp[n][i];
        if(cur < mn && cur != -1) mn = cur;
    }
    return mn;
}

ll dijkstra()
{
    
    // initialize
    for(int i = 0 ; i < MAX_N; ++i) memset(dp[i], -1, sizeof(dp[i]));

    dp[1][0] = 0;
    pq.push({0, {0, 1}});
    
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();  // pq: {cost, {# of paved road, position}}
        ll curCost = -cur.first;
        int curCnt = cur.second.first;  // current # of paved road
        int curNode = cur.second.second;
        
        if(curCost > dp[curNode][curCnt]) continue;
        
        for(auto e: adj[curNode])       // adj: {cost, position}
        {
            ll nextCost = e.first + curCost;
            int nextNode = e.second;
            
            // If the curent # of paved road lower than k
            // it means road pavement is available = no cost
            if(curCnt < k)
            {
                // if the dp is uninitialized or bigger than the current cost
                if(dp[nextNode][curCnt + 1] == -1 || dp[nextNode][curCnt + 1] > curCost)
                {
                    dp[nextNode][curCnt + 1] = curCost;          // update information
                    pq.push({-curCost, {curCnt + 1, nextNode}}); // pq: {cost, {# of paved road, position}}
                }
            }
            
            // not using road pavement = calculate cost
            // if the dp is uninitialized or find the new way
            if(dp[nextNode][curCnt] == -1 || dp[nextNode][curCnt] > nextCost)
            {
                dp[nextNode][curCnt] = nextCost;          // update information
                pq.push({-nextCost, {curCnt, nextNode}}); // pq: {cost, {# of paved road, position}}
            }
        }
    }
    return findMin();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for(int i = 0 ; i < m; ++i)
    {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    cout << dijkstra() << "\n";
    return 0;
}


