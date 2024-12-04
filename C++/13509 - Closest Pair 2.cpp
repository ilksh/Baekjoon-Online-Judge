#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    int x, y, idx;
};

map<int, int> compCoor;


vector<int> seg;
vector<Point> points;

int dist[200003];
int N;

void init() {
    for (int i = N - 1; i > 0; i--) seg[i] = max(seg[i << 1], seg[i << 1 ^ 1]);
}

void update(int i, int val) {
    for (seg[i += N] = val; i > 1; i >>= 1) seg[i >> 1] = max(seg[i], seg[i ^ 1]);
}

int query(int l, int r) {
    int mx = -0x3f7f7f7f;
    for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) mx = max(mx, seg[l++]);
        if (r & 1) mx = max(mx, seg[--r]);
    }
    return mx;
}

void solve() {
    seg.clear();
    compCoor.clear();
    vector<int> tmp;

    for (int i = 0; i < N; i++) tmp.push_back(points[i].y);
    sort(tmp.begin(), tmp.end());

    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    int Ysz = tmp.size();

    for (int i = 0; i < Ysz; i++) compCoor[tmp[i]] = i;

    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    for (int i = 0; i < N - 1; i++) {
        if (points[i].x == points[i + 1].x && points[i].y == points[i + 1].y)
            dist[points[i].idx] = dist[points[i + 1].idx] = 0;
    }
    seg.resize(2 * N, -0x3f7f7f7f);
    
    for (int i = 0; i < N; i++) {
        int x = points[i].x, y = points[i].y, idx = points[i].idx;
        int ytrans = compCoor[y];
        int val = query(0, ytrans);
        if (x + y - val < dist[idx]) dist[idx] = x + y - val;
        update(ytrans, x + y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    fill(dist, dist + N, 0x3f3f3f3f);
    points.resize(N);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y, i};
    }
    
    solve();
    for (int i = 0; i < N; i++) points[i].x = -points[i].x;
    solve();
    for (int i = 0; i < N; i++) points[i].y = -points[i].y;
    solve();
    for (int i = 0; i < N; i++) points[i].x = -points[i].x;
    solve();
    for (int i = 0; i < N; i++) cout << dist[i] << '\n';

    return 0;
}
