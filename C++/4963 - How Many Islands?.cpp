#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m;
int dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
int dx[8] = {0, 0, -1, 1, 1,-1, -1,1};

bool OOB(int y, int x)
{
    return y < 0 || y >= m || x < 0 || x >= n;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        
        bool island[m+1][n+1];
        
        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                cin >> island[row][col];
            }
        }
        
        queue<pii> q;
        bool visited[m][n];
        
        memset(visited, false, sizeof(visited));
        
       
        int islandCnt = 0;
        
        for(int row = 0 ; row < m ; ++row) {
            for(int col = 0 ; col < n; ++col){
                if (island[row][col] && !visited[row][col])
                {
                    q.push({row, col});
                    visited[row][col] = true;
                    islandCnt++;
                    while(!q.empty())
                    {
                        auto cur = q.front();
                        q.pop();
                        for(int dir = 0; dir < 8; ++dir)
                        {
                            int nx = cur.second + dx[dir];
                            int ny = cur.first + dy[dir];
                            
                            if(OOB(ny, nx) || visited[ny][nx]) continue;
                            
                            if(island[ny][nx])
                                q.push({ny, nx});
                            
                            visited[ny][nx] = true;
                        }
                        
                    }
                }
            }
        }
       
        cout << islandCnt << "\n";
    }
    return 0;
}
