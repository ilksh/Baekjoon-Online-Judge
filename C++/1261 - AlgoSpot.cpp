#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;     // {row, col}
typedef pair<int, pii> ipii;    // {# of wall to break, {row, col}}
priority_queue<ipii> pq;

const int MAX = 1e2 + 2;
const int INF = 1e9;

int n, m;    // width, length
int maze[MAX][MAX];    
int rst[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool OOB(int row, int col);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // input
    for(int row = 0; row < m; ++row) {
        string temp;
        cin >> temp;
        for(int col = 0 ; col < n; ++col)
        {
            int tempNum = temp[col] - '0';
            maze[row][col] = tempNum;
            rst[row][col] = INF;   // initialize
        }
    }

    ipii start = {0, {0,0}};
    rst[0][0] = 0;
    pq.push(start);

    while(!pq.empty())
    {
        ipii cur = pq.top(); pq.pop();
        int curCost =  (-1) * cur.first;
        pii curCoord = cur.second;
        int curRow = curCoord.first;
        int curCol = curCoord.second;

        for(int dir = 0 ; dir < 4; ++dir)
        {
            int nRow = curRow + dy[dir];
            int nCol = curCol + dx[dir];

            if (OOB(nRow, nCol)) continue;

            int nCost = curCost + maze[nRow][nCol];

            // find a new way
            if(nCost < rst[nRow][nCol])
            {
                rst[nRow][nCol] = nCost;
                ipii nextInfo = {-nCost, {nRow, nCol}};
                pq.push(nextInfo);
            }
        }
    }

    cout << rst[m-1][n-1] << endl;

    return 0;
}

bool OOB(int row, int col)
{
    return row < 0 || row >= m || col < 0 || col >= n ;
}


