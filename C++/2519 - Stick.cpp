#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_STICKS = 3030;
constexpr int MAX_NODES = MAX_STICKS * 2;

int n; 
int X1[MAX_STICKS], Y1[MAX_STICKS], X2[MAX_STICKS], Y2[MAX_STICKS];

vector<int> graph[MAX_NODES], rev_graph[MAX_NODES];
vector<int> finish_stack; 

int visited[MAX_NODES], scc_id[MAX_NODES];

constexpr int inverse(int x) {return x >= 3 * n ? x - 3 * n : x + 3 * n;}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int res = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    return res > 0 ? 1 : -1;
}

bool isCrossing(int i, int j) {
    int t1 = ccw(X1[i], Y1[i], X2[i], Y2[i], X1[j], Y1[j]) * ccw(X1[i], Y1[i], X2[i], Y2[i], X2[j], Y2[j]);
    int t2 = ccw(X1[j], Y1[j], X2[j], Y2[j], X1[i], Y1[i]) * ccw(X1[j], Y1[j], X2[j], Y2[j], X2[i], Y2[i]);
    return t1 < 0 && t2 < 0;
}

void dfs1(int node) {
    visited[node] = 1;
    for (auto next : graph[node]) {
        if (!visited[next]) dfs1(next);
    }
    finish_stack.push_back(node);
}

void dfs2(int node, int id) {
    scc_id[node] = id;
    for (auto next : rev_graph[node]) {
        if (!scc_id[next]) dfs2(next, id);
    }
}

void computeScc() {
    for (int i = 0; i < 6 * n; i++) {
        if (!visited[i]) dfs1(i);
    }

    reverse(finish_stack.begin(), finish_stack.end());

    int scc_count = 1;
    for (auto node : finish_stack) {
        if (!scc_id[node]) dfs2(node, scc_count++);
    }
}

void add_edge(int u, int v) {
    graph[u].push_back(v); 
    rev_graph[v].push_back(u); 
    graph[inverse(v)].push_back(inverse(u)); 
    rev_graph[inverse(u)].push_back(inverse(v));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int total_sticks = 3 * n;

    // 막대기 좌표 입력
    for (int i = 0; i < total_sticks; i++) {
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    }

    // 학생별 제약 조건 추가
    for (int i = 0; i < n; i++) {
        int a = 3 * i, b = 3 * i + 1, c = 3 * i + 2;
        add_edge(a, inverse(b)); // A → ¬B
        add_edge(a, inverse(c)); // A → ¬C
        add_edge(b, inverse(a)); // B → ¬A
        add_edge(b, inverse(c)); // B → ¬C
        add_edge(c, inverse(a)); // C → ¬A
        add_edge(c, inverse(b)); // C → ¬B
    }

    for (int i = 0; i < total_sticks; i++) {
        for (int j = i + 1; j < total_sticks; j++) {
            if (isCrossing(i, j)) {
                add_edge(inverse(i), j); // ¬i → j
                add_edge(inverse(j), i); // ¬j → i
            }
        }
    }

    computeScc();

    for (int i = 0; i < total_sticks; i++) {
        if (scc_id[i] == scc_id[inverse(i)]) {
            cout << -1 << "\n"; // collision
            return 0;
        }
    }

    vector<int> result;
    for (int i = 0; i < total_sticks; i++) {
        if (scc_id[i] > scc_id[inverse(i)]) {
            result.push_back(i + 1); 
        }
    }

    cout << result.size() << "\n";
    for (auto x : result) cout << x << " ";
    cout << "\n";

    return 0;
}
