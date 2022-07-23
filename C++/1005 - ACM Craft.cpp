#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;

const int MAX_N = 1e3 + 1;

int building[MAX_N];
int inDegree[MAX_N];

int main()
{
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while(tc--)
    {
        int n, k;  // n = # of buildings, k = # of construction rules
        cin >> n >> k;
        
        for(int i=0; i<n; ++i)
            cin >> building[i];
        
        memset(inDegree, 0, sizeof(inDegree));
        // vector<vi> adj(n, vi());
        vector<int> adj[MAX_N];
        
        while(k--)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            inDegree[b]++;
        }
        
        int w;
        cin >> w; w--;
    
        int ans = 0;
        priority_queue<pii> pq;
        
        for(int i=0; i<n; ++i)
        {
            if(inDegree[i] == 0)
                pq.push({-building[i], i});
        }
        
        while(true)
        {
            int curTime = -pq.top().first;
            int curNode = pq.top().second;
            pq.pop();
            
            ans = max(ans, curTime);
            
            if(curNode == w) break;
            
            auto vSz = adj[curNode].size();
            
            for(int i=0; i<vSz; ++i)
            {
                int nxt =  adj[curNode][i];
                
                if(--inDegree[nxt] == 0)
                    pq.push({-(curTime + building[nxt]), nxt});
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
