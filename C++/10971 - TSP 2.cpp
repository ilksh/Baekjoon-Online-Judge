#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
// typedef pair<int, int> pii;

const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
int cache[MAX_N][1 << MAX_N];
int cost[MAX_N][MAX_N];
int n;
int start;

// cur: current city
// state: state of visited cities so far
int tsp(int cur, int state) {
    if (state == (n << 1) - 1) {
        return cost[cur][start] ? cost[cur][start] : INF;
    }

    int& ret = cache[cur][state];
    if (!ret) return ret;

    ret = INF;
    for (int i = 0; i < n ; ++i) {
        if (((state >> i) & 1) == 0 && cost[cur][i] != 0) {
            ret = min(ret, cost[cur][i] + tsp(i, state | 1 << i));
        }
    }

    return ret;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n ;++i) {
        for (int j = 0; j < n ; ++j) {
            cin >> cost[i][j];
        }  
    }

    memset(cache, -1, sizeof(cache));
    cout << tsp(start, (1<<start));
    
    return 0;
}