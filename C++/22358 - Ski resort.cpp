#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX_N = 1e5 + 5;
const int MAX_K = 11;

int N, M, K, S, T;
ll dp[MAX_N][MAX_K];        // dp[x][cnt] = longest time when using cnt number lift from s to x
int inDegree[MAX_N][MAX_K];

bool visited[MAX_N][MAX_K];

vector<pii>adj[MAX_N];      // {target, cost}
vector<int>revAdj[MAX_N];   // {target, 0}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> K >> S >> T;
    
    for(int i=0; i<M; ++i)
    {
        int a, b, weight;
        
        cin >> a >> b >> weight;
        
        adj[a].push_back({b, weight});  // from a to b (general path)
        revAdj[b].push_back(a);         // from b to a (using lifts)
    }
    
    // initialzie dp
    memset(dp, -1, sizeof(dp));
    
    queue<pii> q;   // {cur, cnt}
    q.push({S, 0});
    visited[S][0] = true;
    
    // bfs
    while(!q.empty())
    {
        pii cur = q.front(); q.pop();
        
        // call by reference
        for(auto& e: adj[cur.first])
        {
            inDegree[e.first][cur.second]++;
            
            if(!visited[e.first][cur.second])
            {
                q.push({e.first, cur.second});
                visited[e.first][cur.second] = true;
            }
        }
        
        // max # of using lift is k times
        if(cur.second == K)
            continue;
        
        for(int nxt: revAdj[cur.first])
        {
            inDegree[nxt][cur.second + 1]++;
            
            if(!visited[nxt][cur.second + 1])
            {
                q.push({nxt, cur.second + 1});
                visited[nxt][cur.second + 1] = true;
            }
        }
    }
    
    dp[S][0] = 0;
    q.push({S, 0});
    while(!q.empty())
    {
        pii cur = q.front(); q.pop();
        
        for(auto& e: adj[cur.first])
        {
            // calculate time
            dp[e.first][cur.second] = max(dp[e.first][cur.second], dp[cur.first][cur.second] + e.second);
            
            // InDegree is 0 = No path to the current node
            if(--inDegree[e.first][cur.second] == 0)
                q.push({e.first, cur.second});
        }
        
        // max # of using lift is k times
        if(cur.second == K)
            continue;
        
        // renew information when using lifts from current status
        for(int nxt: revAdj[cur.first])
        {
            dp[nxt][cur.second + 1] = max(dp[nxt][cur.second + 1], dp[cur.first][cur.second] + 0);
            
            if(--inDegree[nxt][cur.second + 1] == 0)
                q.push({nxt, cur.second + 1});
        }
    }
    
    ll ret = dp[T][0];
    
    // lift can be used up to K times
    // though # of lifts used is small, it may take up to a maximum time
    for(int i=1; i<=K; ++i)
        ret = max(ret, dp[T][i]);
    
    cout << ret << "\n";
    
    return 0;
}
