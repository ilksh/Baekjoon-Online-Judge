#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii; // {node, cost}
typedef vector<int> vi;

const int INF = 1e9;
const int MAX_N = 1e2 + 2;

vi adj[MAX_N][MAX_N]; // i: node, j = testcase
int dp[MAX_N];

void init() {
    for (int i = 0 ; i < MAX_N ; ++i) dp[i] = INF;
}

void dijskstra(int s, int tc) {
    init();
    queue<pii> q;
    dp[s] = 0;
    q.push(make_pair(s, 0));

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int curNode = cur.first;
        int curCost = cur.second;
        for (auto e : adj[curNode][tc]) {
            int next;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int tc;
    cin >> tc;

    while(--tc) {
        int n , m;
        cin >> n >> m;
        int a, b, c;
        cin >> a >> b >> c;

    }
    return 0;
}