#include<iostream>
#include<queue>
#include<algorithm>
#define MAX_SIZE 101
using namespace std;
typedef struct pair<int, int> pii;
queue<pii> q;
bool visited[MAX_SIZE][MAX_SIZE];
char arr[MAX_SIZE][MAX_SIZE];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
int OOB(int y, int x);
int n;
int red, green, blue,red_green;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				visited[i][j] = true;
				q.push({ i,j });
				if (arr[i][j] == 'R')
					red++;
				if (arr[i][j] == 'G')
					green++;
				if (arr[i][j] == 'B')
					blue++;
	

				while (!q.empty())
				{
					pii cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int ny = cur.first + dy[dir];
						int nx = cur.second + dx[dir];
						if (arr[ny][nx] != arr[cur.first][cur.second])
							continue;
						if (!visited[ny][nx] && !OOB(ny, nx))
						{
							q.push({ ny,nx });
							visited[ny][nx] = true;
						}
							
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		fill(visited[i], visited[i] + n, false);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && arr[i][j] != 'B')
			{
				visited[i][j] = true;
				q.push({ i,j });

				if (arr[i][j] != 'B')
					red_green++;

				while (!q.empty())
				{
					pii cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int ny = cur.first + dy[dir];
						int nx = cur.second + dx[dir];
						if (arr[ny][nx] == 'B')
							continue;
						if (!visited[ny][nx] && !OOB(ny, nx))
						{
							q.push({ ny,nx });
							visited[ny][nx] = true;
						}

					}
				}
			}
		}
	}


	/*cout << "red: " << red << "\n";
	cout << "green: " << green << "\n";
	cout << "blue: " << blue << "\n";
	cout << "red_green: " << red_green;*/
	cout << red + green + blue << "\n";
	cout << blue + red_green ;
}
int OOB(int y, int x)
{
	return y < 0 || y >= n || x < 0 || x >= n;
}