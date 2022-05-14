#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

const int MAX_I = 301;
const int INF = 987654321;
typedef pair<int, int> pii;

queue <pii> q;
int dist[MAX_I][MAX_I];

int length;	// lenght of chessboard
int test_case;

// 8 directions
pii delta[] = { { 2,1}, {1,2}, {-2 ,1 }, {-1 ,2},
					{2 ,-1 }, {1,-2 }, {-1 ,-2 }, {-2 ,-1 }};

int cur_x, cur_y;
int target_x, target_y;

int OOB(int y, int x);

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> test_case;

	while (test_case--)
	{
		// initailize
		while (!q.empty()) {
			q.pop();
		}
		
		// initailize
		memset(dist, -1, sizeof(dist));

		cin >> length;

		// input current coordinate
		cin >> cur_y >> cur_x;

		q.push({ cur_y,cur_x });
		dist[cur_y][cur_x] = 0;

		// input target coordinate
		cin >> target_y >> target_x;
	
		while (!q.empty())
		{
			auto cur = q.front(); q.pop();

			// 8 directions that knight can move
			for (auto dir : delta)
			{
				// ny, nx = coordinate after movement
				int ny = cur.first + dir.first;
				int nx = cur.second + dir.second;

				// Out of boundary
				if (OOB(ny, nx)) continue;

				int new_dist = dist[cur.first][cur.second] + 1;
				
				// the value was not renewed
				if(dist[ny][nx] == -1)
					{	
						dist[ny][nx] = new_dist;
						q.push({ ny,nx });
					}
			} 
		}

		cout << dist[target_y][target_x] << "\n";
	}

}

int OOB(int y, int x)
{
	return y < 0 || y >= length || x < 0 || x >= length;
}