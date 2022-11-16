#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAX = 55;

typedef pair<int, int> pii;     // {row, col}
typedef pair<int, pii> ipii;    // {# of room to change, {row, col}}
priority_queue<ipii> pq;

int maze[MAX][MAX];
int rst[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;

// out of boundary
bool OOB(int row, int col)
{
    return row < 0 || row >= n || col < 0 || col >= n ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    // input
    for(int i = 0 ; i < n; ++i){
        string temp;
        cin >> temp;
        for(int j = 0 ; j < n; ++j)
        {
            int tempNum = temp[j] - '0';
            maze[i][j] = tempNum;
            rst[i][j] = INF;
        }
    }
    
    // start point is always (0,0)
    rst[0][0] = 0;
    pq.push({0, {0,0}});
    
    // dijkstra
    while(!pq.empty())
    {
        ipii cur = pq.top(); pq.pop();
        int curCost =  (-1) * cur.first;
        pii curCoord = cur.second;
        int curRow = curCoord.first;
        int curCol = curCoord.second;
        
        // move in 4 direction (up, down, right, left)
        for(int dir = 0 ; dir < 4; ++dir)
        {
            int nRow = curRow + dy[dir];
            int nCol = curCol + dx[dir];
            
            if(OOB(nRow, nCol)) continue;
            
            // since 
            int nextMaze = (maze[nRow][nCol]) ? 0 : 1;
            int nCost = curCost + nextMaze;
            
            // update info
            if(nCost < rst[nRow][nCol])
            {
                rst[nRow][nCol] = nCost;
                pq.push({-nCost, {nRow, nCol}});
            }
            
        }
        
    }
    
    cout << rst[n - 1][n - 1] << endl;
    
    return 0;
}
