#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

queue< pair<int,int> > q;

int OOB(int y, int x);
int dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
int N;

int main()
{
    scanf("%d", &N);

    int groupname=-1;
    int groupsize[25*25]={0};

    int arr[25][25];
    int visited[25][25]={0};

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%1d",&arr[i][j]);

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            if(visited[i][j]!=1 && arr[i][j] == 1)
            {
                q.push({i,j});
                visited[i][j]=1;
                groupname++;

                while(!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for(int dir=0; dir<4;dir++)
                    {
                        int ny = cur.first+dy[dir];
                        int nx = cur.second+dx[dir];
                        if(arr[ny][nx]==1)
                            if(!visited[ny][nx] && !OOB(ny,nx))
                            {
                                visited[ny][nx]= 1;
                                groupsize[groupname]++;
                                q.push({ny,nx});
                            }
                    }
                }
            }
        }

    //for(int i=0;i<=groupname;i++)
    //    printf("%d : %d\n",i,groupsize[i]+1);
    sort(groupsize,groupsize+groupname+1);

    printf("%d\n",groupname+1);
    for(int i=0;i<=groupname;i++)
        printf("%d\n",groupsize[i]+1);

}


int OOB(int y, int x)
{
    return y<0||y>=N||x<0||x>=N ;
}
