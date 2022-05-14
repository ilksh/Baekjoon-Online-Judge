#include<stdio.h>
#include<queue>
using namespace std;

queue <int> q;
int n, m;
bool arr[1001][1001]={0};
bool visited[1001][2]={0};

void dfs(int num_1)
{
    visited[num_1][0]=1;
    for(int i=1; i<=n; i++)
    {
        if(arr[num_1][i] && !visited[i][0])
        {
            printf("%d ", i);
            dfs(i);
        }
    }
}

void bfs(int num_2)
{
    q.push(num_2);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        visited[cur][1]= 1;
        printf("%d ",cur);
        for(int i=1;i<=n;i++)
            if(arr[cur][i]&&!visited[i][1])
            {
                q.push(i);
                visited[i][1]=1;
            }
    }

    /*for(int i=1; i<=n; i++)
    {
        if(arr[num_2][i] && !visited[i][1])
        {
            visited[i][1] = true;
            q.push(i);
            printf("%d ",i);
            while(!q.empty())
            {
                int cur = q.front();
                q.pop();
                for(int j=1; j<=n;j++)
                {
                    if(arr[cur][j] && !visited[j][1])
                        q.push(j);
                }
            }
        }
    }*/
}

int main()
{
    int start;
    scanf("%d %d %d", &n, &m, &start);

    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d", &a,&b);
        arr[a][b] = true;
        arr[b][a] = true;
    }
    visited[start][0] = true;
    printf("%d ", start);
    dfs(start);
    visited[start][1] = true;
    printf("\n");
    bfs(start);

}
