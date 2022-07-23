#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;    // {length, node}

const int MAX_N = 1e2 + 2;
const int INF = 0x3f3f3f3f;

int n, m, r;        // number of region, search scope, number of road

vector<pii> v[MAX_N];

int item[MAX_N];
int dp[MAX_N];      // total distance from the ith node to all adjacent node

void dijkstra(int start)
{
    for(int i=1; i<n+1; ++i)
        dp[i] = INF;
    
    priority_queue<pii> pq; // initialize queue
    
    pq.push({0, start});
    dp[start] = 0;
    
    while(!pq.empty())
    {
        auto cur = pq.top();pq.pop();
        
        // unnecessary node
        if(dp[cur.second] < -cur.first)
            continue;
        
        for(auto e: v[cur.second])
        {
            int next_cost = (-1) * cur.first + e.first;
            int next = e.second;
            
            // update information
            if(next_cost < dp[next])
            {
                dp[next] = next_cost;
                pq.push({-dp[next], next});
            }
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> r;
    
    for(int i=1; i<n+1; ++i)
        cin >> item[i];
    
    for(int i=0; i<r; ++i)
    {
        int node1, node2, length;
        
        cin >> node1 >> node2 >> length;
        
        v[node1].push_back({length, node2});
        v[node2].push_back({length, node1});
    }
    
    int rst = 0;
    
    for(int i=1; i<n+1; ++i)
    {
        dijkstra(i);
        
        int temp = 0;
        
        for(int j=1; j<n+1; ++j)
        {
            // able to search
            if(dp[j] <= m)
                temp += item[j];
        }
        
        rst = max(rst, temp);
    }
    
    cout << rst;
    
    return 0;
}
