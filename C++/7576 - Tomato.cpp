#include<stdio.h>
#include<queue>

using namespace std;
queue<pair<int,int>> q;

int tomato[1001][1001];
int OOB(int y, int x);
int m,n;
int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

int main()
{
    int day=-1;
    int cnt=0;

    scanf("%d %d", &m, &n);
    int tomato_number= m*n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &tomato[i][j]);

            if(tomato[i][j]==1)
            {
                q.push({i,j});
                cnt++;
            }
            if(tomato[i][j]==-1)
                cnt++;
        }
    }


    while(!q.empty())
    {
        int qsize=q.size();
        while(qsize--){
            pair <int, int> start = q.front();
            q.pop();
            for(int dir=0; dir<4; dir++)
            {
                int ny = start.first + dy[dir];
                int nx = start.second + dx[dir];
                if(tomato[ny][nx] ==0 && !OOB(ny,nx)){
                    q.push({ny, nx});
                    tomato[ny][nx]=1;
                    cnt++;
                }
            }
        }
        day++;
    }

    if(cnt == tomato_number)
        printf("%d",day);
    else
        printf("-1");
}

int OOB(int y, int x)
{
    return y<0||y>=n||x<0||x>=m ;
}
