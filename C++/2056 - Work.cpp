#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e4 + 4;

int inDegree[MAX_N];        // number of ways reaching ith node
int work[MAX_N];            // time to complete ith work
int ans[MAX_N];

vector<int> adj[MAX_N];
queue<int> q;

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    memset(inDegree, 0, sizeof(inDegree));
    
    for(int i=1; i<=n; ++i)
    {
        cin >> work[i];
        
        int precedence;
        cin >> precedence;
        
        inDegree[i] = precedence;
        
        for(int j=0; j< precedence; ++j)
        {
            int prev;
            cin >> prev;

            adj[prev].push_back(i);
        }
    }
    
    for(int i=1; i<=n; ++i)
    {
        if(inDegree[i] == 0)
            q.push(i);
        
        ans[i] = work[i];
    }
    
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        
        for(auto e: adj[cur])
        {
            int nxt = e;
            
            ans[nxt] = max(ans[nxt], ans[cur] + work[nxt]);
            
            if(--inDegree[nxt] == 0)
                q.push(nxt);
        }
    }
    
    int rst = -1;
    
    for(int i=1; i<=n; ++i)
        rst = max(rst, ans[i]);
    
    cout << rst << "\n";
    
    return 0;
}
