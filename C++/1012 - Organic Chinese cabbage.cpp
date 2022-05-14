#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

queue<pair<int,int>> q;
int OOB(int y, int x);

int OOB(int y, int x);

int M;                  
int N;                  
int K;                  

bool arr[50][50];
bool visited[50][50];

int dx[4]= {-1,1,0,0};
int dy[4]= {0,0,1,-1};


int main(void)
{
    int T;
    int cnt=0;
    int cnt_imsi[100];

    int sequence=0;

    scanf("%d", &T);

    for(int z=0;z<T;z++)
    {
        scanf("%d %d %d", &M, &N,&K);

        for(int i=0;i<K;i++)
        {
            int a,b;
            scanf("%d %d", &a, &b);
            arr[b][a] =true;
        }

        for(int i=0;i<N;i++)
            for(int j=0; j<M;j++)
            {
                if(!visited[i][j] && arr[i][j])
                {
                    q.push({i,j});
                    cnt++;
                    visited[i][j]=true;

                    while(!q.empty())
                    {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for(int dir=0; dir<4; dir++)
                        {
                            int ny= cur.first+dy[dir];
                            int nx= cur.second+dx[dir];

                            if(OOB(ny,nx)) continue;
                            if(arr[ny][nx]&&!visited[ny][nx])
                            {
                                visited[ny][nx] = true;
                                q.push({ny,nx});
                            }
                        }
                    }
                }
            }

        /*printf("======\n");
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
                printf("%d ", visited[i][j]);
            printf("\n");
        }
        printf("======\n");*/
        cnt_imsi[z] = cnt;
        sequence++;
        cnt=0;

        for(int i=0;i<N;i++)
            for(int j=0; j<M;j++)
            {
                arr[i][j]=0;
                visited[i][j]=0;
            }
        M=0, N=0, K=0;
    }

    for(int i=0;i<sequence;i++)
        printf("%d\n",cnt_imsi[i]);

    return 0;
}

int OOB(int y, int x)
{
    return y<0 || y>=N || x<0 || x>=M;
}


