#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;                  
int p[15];     
int cost[16][16];          
int dp[15][1 << 15];       

int tsp(int now, int state) {
    if (state == (1 << (n + 1)) - 1) {
        return cost[now][n]; 
    }

    int& result = dp[now][state];
    if (result != -1) return result;

    result = INF;

    for (int next = 0; next < n + 1; ++next) {
        bool alreadyVisited = state & (1 << next); 
        bool canVisit = cost[now][next] < INF;       
        // When no prerequisites are required (p[next] == next)
        // When prerequisites exist, ensure the required city has been visited beforehand.
        bool prerequisiteMet = p[next] == next || (state & (1 << p[next]));

        if (!alreadyVisited && canVisit && prerequisiteMet) {
            result = min(result, tsp(next, state | (1 << next)) + cost[now][next]);
        }
    }

    return result;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--; 
    }

    memset(cost, INF, sizeof(cost));
    memset(dp, -1, sizeof(dp));

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--; 
        cost[u][v] = min(cost[u][v], w);
    }


    int result = tsp(n, 1 << n);

    cout << (result < INF ? result : -1) << "\n";
    return 0;
}
