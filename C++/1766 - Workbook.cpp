#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

priority_queue <int> pq;
vector <int> v[32001];

int n, m;
int q1, q2;
int indegree[32001];
bool visited[32001];
int cnt, print_data[32001];

int main(void)
{
    scanf("%d %d", &n, &m);

    for(int i=0; i<m;i++)
    {
        scanf("%d %d", &q1,&q2);
        v[q1].push_back(q2);
        indegree[q2]++;
    }

    for(int i=1; i<=n ;i++)
    {
        if(indegree[i]==0){
            visited[i] = true;
            pq.push(-i);
        }
    }

    while(!pq.empty())
    {
        int cur = -1*pq.top(); pq.pop();
        //print_data[cnt] = cur;
        cnt++;
        printf("%d ", cur);

        for(int i=0; i<v[cur].size(); i++){
            int nxt = v[cur][i];
            if(--indegree[nxt] == 0 && !visited[nxt]){
                visited[nxt] = true;
                pq.push(-nxt);
            }
        }

    }

}
