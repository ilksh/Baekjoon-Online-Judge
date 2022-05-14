#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;
vector <int> v[1001];
queue <int> q;

int indegree[1001];
bool visited[1001];
int m ,n;
int from = -1, to = -1;
int idx, cnt;
int print_answer[1001];

int main()
{
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++)
    {
        int charge, from, to;
        scanf("%d", &charge);
        if(charge >= 1)
            scanf("%d", &from);

        for(int j=0; j<charge-1; j++)
        {
            scanf("%d", &to);
            v[from].push_back(to);
            indegree[to]++;
            from = to;
        }
    }

    for(int i=1; i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            visited[i]=true;
        }

    }

    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        print_answer[idx++] = cur;
        cnt++;
        for(int i=0; i<v[cur].size(); i++)
        {
            int next =v[cur][i];
            if(--indegree[next]==0 && !visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    if(cnt<n)
        printf("0");
    else
    {
        for(int i=0; i<idx;i++)
            printf("%d\n", print_answer[i]);
    }
}


