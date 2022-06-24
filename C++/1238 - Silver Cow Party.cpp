#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


typedef pair<int, int> pii;
const int INF = 1e9 + 1;
const int MAX_N = 1e3 + 1;

priority_queue<pii> pq;
vector<pii> adj[MAX_N];

int result[MAX_N];
int n, m, x;    //n = # of node, m = # of edge, x = end
int from, to , weight;
int ans = -1;

int dijkstra(int start, int end)
{
    for(int i=0; i< n+1; i++)
        result[i] = INF;
    
    pq = priority_queue<pii>();
    
    result[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty())
    {
        pii cur = pq.top(); pq.pop();
        
        if (result[cur.second] != -1 * cur.first)
            continue;;
        
        for (pii edge:adj[cur.second])
        {
            int next_node = edge.second;
            int next_result = edge.first + (-1*cur.first);
            
            if (next_result < result[next_node])
            {
                result[next_node] = next_result;
                pq.push({-1*result[next_node], next_node});
            }
        }
        
    }
    
    return result[end];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> x;
    
    for(int i=0; i<m; i++)
    {
        cin >> from >> to >> weight;
        adj[from].push_back({weight, to});
    }
    
    for(int i=1; i<n+1; i++)
    {
        int temp = dijkstra(i, x) + dijkstra(x, i);
        ans = max(ans, temp);
    }
    
    cout << ans<<"\n";
    
    
    
    return 0;
}
