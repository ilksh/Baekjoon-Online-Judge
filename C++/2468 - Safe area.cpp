#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

queue <pair<int, int>> q;
#define MAX_SIZE 101

int OOB(int y, int x);
int arr[MAX_SIZE][MAX_SIZE];
int standard[MAX_SIZE];
int dy[4] = {-1,1,0,0}, dx[4] = {0,0,-1,1};

bool area_visited[MAX_SIZE][MAX_SIZE];
bool rain_visited[MAX_SIZE];

int minimum=0,idx=0,cnt=0;
int n;

void safe_area(int compare)
{
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!area_visited[i][j])
            {
                area_visited[i][j] = true;

                if(arr[i][j] > compare)
                {
                    q.push({i,j});
                    while(!q.empty())
                    {
                        pair <int, int> cur = q.front();
                        q.pop();
                        for(int dir=0 ; dir<4; dir++)
                        {
                            int ny = cur.first + dy[dir];
                            int nx = cur.second + dx[dir];
                            if( (arr[ny][nx] > compare) && !area_visited[ny][nx] && !OOB(ny,nx))
                            {
                                q.push({ny,nx});
                                area_visited[ny][nx] = true;
                            }
                        }
                    }
                    cnt++;
                }

            }
        }
    }
    if (cnt > minimum)
        minimum = cnt;
}
int main()
{
    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n ;j++)
        {
            int height;
            cin >> height;
            arr[i][j] = height;
            if(!rain_visited[height])
            {
                rain_visited[height] = true;
                standard[idx++] = height;
            }
        }
    }

    for(int i=0; i<idx;i++)
    {
        safe_area(standard[i]);
        cnt = 0;
        for(int i=0; i<n;i++)
            fill(area_visited[i], area_visited[i]+n,0);
    }

    if(minimum==0)
        cout<< "1";
    else
        cout <<minimum<<endl;

}

int OOB(int y, int x)
{
    return y<0||y>=n||x<0||x>=n ;
}


