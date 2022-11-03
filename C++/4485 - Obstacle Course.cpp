#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int OOB(int y, int x, int n);

int cnt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    while(true){
        int n;
        cin >> n;
        if(n == 0 ) break;
        
        priority_queue<pii> pq;
        
        int mars[n][n];
        int result[n][n];
        
        memset(result, INF, sizeof(result));
            
        cnt++;
    
        for(int row = 0; row < n; ++row){
            for(int col = 0; col < n; ++col){
                cin >> mars[row][col];
            }
        }
        result[0][0] = mars[0][0];
        
        pq.push({0,0});
        
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            
            for(int dir = 0; dir < 4; ++dir){
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                
                if(OOB(ny, nx, n))
                    continue;
                
                int nextScore = mars[ny][nx];
                int newResult = result[cur.first][cur.second] + nextScore;
                
                if(result[ny][nx] > newResult){
                    pq.push({ny, nx});
                    result[ny][nx] = newResult;
                }
            }
        }
        cout << "Problem " << cnt << ": "<< result[n-1][n-1] << "\n";
    }
}


int OOB(int y, int x, int n){
    return y < 0 || y >= n || x < 0 || x >= n;
}

