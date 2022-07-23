#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_V = 1e2 + 2;  // max number of edge

int n, m ;  // n = number of node, m = number of edge
int dist[MAX_V][MAX_V];

void floydWarshall()
{
    for(int pass=1; pass<= n; ++pass){
        for(int from = 1; from <= n; ++from){
            for(int to = 1; to <= n; ++to){
                if(from == to) continue;
                
                dist[from][to] = min(dist[from][pass] + dist[pass][to],
                                     dist[from][to]);
            }
        }
    }
    
    for(int from = 1; from <= n; ++from){
        for(int to = 1; to<= n; ++to)
            cout << (dist[from][to] == INF ? 0: dist[from][to])<<" ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    memset(dist, 0x3f, sizeof(dist));
    
    cin  >> n >> m;
    
    int u, v, w;
    
    for(int i=0; i<m; ++i)
    {
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }
    
    floydWarshall();
    
    return 0;
    
}

