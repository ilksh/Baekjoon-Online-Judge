#include<stdio.h>
#include<queue>

using namespace std;

queue<int> q;

bool adj[101][101];
bool visited[101];
int cnt=0;

int main()
{
    int com_num;
    int com_pair_num;
    int a,b;

    scanf("%d", &com_num);
    scanf("%d", &com_pair_num);

    for(int i=1; i<=com_pair_num; i++)
    {
        scanf("%d %d", &a, &b);
        adj[a][b]= true;
        adj[b][a]= true;
    }


    q.push(1);
    visited[1]=true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cnt++;

        for(int k=1; k<=com_num; k++)
        {
            if(adj[cur][k]&& !visited[k])
            {
                visited[k]=true;
                q.push(k);
            }
        }

    }
    printf("%d",cnt-1);
    /*printf("======\n");
    for(int i=1;i<=com_num;i++)
    {
        for(int j=1;j<=com_num;j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }*/
}



