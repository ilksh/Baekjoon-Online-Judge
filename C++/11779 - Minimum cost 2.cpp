#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9 +1;
const int MAX_N = 1e3 + 1;

priority_queue<pii> pq;
vector <pii> adj[MAX_N];
vector<int> route[MAX_N];
int dist[MAX_N];

int n;  // number of city
int m;  // number of bus

int from, to, weight;
int start, terminal;

void route_update(int cur, int nxt)
{
    route[nxt].clear();
    
    for(auto elem: route[cur])
        route[nxt].push_back(elem);
    
    route[nxt].push_back(cur);
}

int dijkstra(int s, int e)
{
    dist[s] = 0;
    pq.push({0, s});
    
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        
        if(dist[cur.second] < -1 * cur.first)
            continue;
        
        for(auto edge : adj[cur.second])
        {
            int next_node = edge.second;
            int next_dist = edge.first + (-1 * cur.first);
            
            if(next_dist < dist[next_node]) //find the faster route
            {
                dist[next_node] = next_dist;
                pq.push({-1*next_dist, next_node});
                route_update(cur.second, next_node); //update the route
            }
        }
    }
    
    return dist[e];
}

void route_print(int end)
{
    cout << route[end].size() + 1<<"\n";
    
    for(auto elem: route[end])
        cout << elem<<" ";
    cout << end<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    for(int i =0; i< MAX_N+1; i++)
        dist[i] = INF;
    
    cin >> n;
    cin >> m;
    
    for(int i=0; i< m; i++)
    {
        cin >> from >> to >> weight;
        adj[from].push_back({weight, to});
    }
    
    cin >> start >> terminal;
    
    cout << dijkstra(start, terminal)<<"\n";
    
    route_print(terminal);
    
    return 0;
}
