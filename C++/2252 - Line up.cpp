#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

priority_queue <int> pq;
vector <int> v[32001];

int indegree[32001];
bool visited[32001];
int print_data[32001];
int cnt;
int m,n;

int main()
{
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        v[from].push_back(to);
        indegree[to]++;
    }

    for(int i=1; i<=n; i++)
    {
        if(indegree[i] == 0)
        {
            visited[i] = true;
            pq.push(-i);
        }
    }

    while(!pq.empty())
    {
        int cur = -1*pq.top(); pq.pop();
        printf("%d ",cur);
        for(int i=0; i<v[cur].size(); i++)
        {
            int next = v[cur][i];
            if(--indegree[next] == 0 && !visited[next])
            {
                visited[next]= true;
                pq.push(-next);
            }
        }
    }

}
