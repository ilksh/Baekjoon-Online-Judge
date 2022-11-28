#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int MAX_N = 1e3 + 3;

vector<pii> adj[MAX_N];
priority_queue<pii> pq;

priority_queue<int> rst[MAX_N];  // store all possible results

int n,m,k;  // n: # of city, m: # of road
int a,b,c;  // weight from a to b is c
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m >> k;
    
    // input data
    for(int i = 0 ; i < m ; ++i)
    {
        cin >> a >> b >> c;
        adj[a - 1].push_back({c, b - 1});
    }
    
    rst[0].push(0); // start
    pq.push({0,0});
    
    // dijkstra
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        int curCost = -cur.first;
        int curNode = cur.second;
        
        // see all possible adjacent nodes
        for(auto e:adj[curNode])
        {
            int nextCost = e.first + curCost;
            int nextNode = e.second;
            int numOfNextRoutes = (int) rst[nextNode].size();
            bool pushSign = false;
            
            // Since we are looking for the kth shortest route,
            // if the # of candidate paths are smaller than k, there is no need to compare
            if(numOfNextRoutes < k)
            {
                rst[nextNode].push(nextCost);
                pushSign = true;
            }
            else
            {
                // update information
                if(nextCost < rst[nextNode].top())
                {
                    rst[nextNode].pop();
                    rst[nextNode].push(nextCost);
                    pushSign = true;
                }
            }
            
            if(pushSign) pq.push({-nextCost, nextNode});
        }
    }
    
    for(int i = 0 ; i < n; ++i)
    {
        // Implicit conversion loses integer precision: (int) requires
        int sz = (int)rst[i].size();
        
        int ans = (sz == k) ? rst[i].top():-1;
        cout << ans << "\n";
    }
    
    return 0;
}
