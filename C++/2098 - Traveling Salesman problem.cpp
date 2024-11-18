#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 16;
const int INF = 0x3f3f3f3f;

int cache[MAX_N][1<<MAX_N], n, cost[MAX_N][MAX_N];
int start = 1;

// cur : current city
// state : state of visited
int tsp(int cur, int state) {
    // visited all cities
    if(state == (1 << n )- 1) {
        return cost[cur][start] ? cost[cur][start] : INF;
    }

    // memoization
    int& ret = cache[cur][state];
    if(ret != -1) return ret;
    

    ret = INF; 
    
    for(int i = 0; i < n; ++i) {
        // i-th city can be visited (initial state 0, visited state 1)
        // Example) Let state = 1011 = visited city 3, 1, 0 and i = 2
        // state >> 2 = 10, & 1 only leaves ""Least Significant Bit""
        auto isCurVisited = (state >> i) & 1;
        if(isCurVisited == 0 && cost[cur][i] != 0) {
            // 1 << i: make ith node visited
            // 1 << 2: 100, 1011 | 0100: 1111
            int nextState = state | (1 << i);

            ret = min(ret, cost[cur][i] + tsp(i, nextState));
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
        cin >> cost[i][j];
    }

    memset(cache, -1, sizeof(cache));
    cout << tsp(start, (1<<start));
    return 0;
}