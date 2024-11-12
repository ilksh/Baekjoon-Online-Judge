#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

constexpr int MAX = 100000;
constexpr int trueX(int x) { return x << 1; }
constexpr int falseX(int x) { return (x << 1) | 1; }
constexpr int notX(int x) { return x ^ 1; }

int room_num, switch_num, order = 1, scc_order = 1;
vi room_state, visited_order, scc_label;
vvi connected_switch, adj;
stack<int> st;

int FindSCC(int now) {
    int min_order = visited_order[now] = order++;
    st.push(now);

    for (int next : adj[now]) {
        if (visited_order[next] == -1)
            min_order = min(min_order, FindSCC(next));
        else if (scc_label[next] == -1)
            min_order = min(min_order, visited_order[next]);
    }

    if (min_order == visited_order[now]) {
        while (true) {
            int t = st.top(); st.pop();
            scc_label[t] = scc_order;
            if (t == now) break;
        }
        ++scc_order;
    }

    return min_order;
}

void TarjanSCC() {
    int total_nodes = switch_num * 2;
    visited_order.assign(total_nodes, -1);
    scc_label.assign(total_nodes, -1);
    order = scc_order = 1;

    for (int i = 0; i < total_nodes; ++i)
        if (visited_order[i] == -1)
            FindSCC(i);
}

bool Solve2SAT() {
    TarjanSCC();
    for (int i = 0; i < switch_num; ++i) {
        if (scc_label[trueX(i)] == scc_label[falseX(i)])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> room_num >> switch_num;
    room_state.resize(room_num);
    connected_switch.resize(room_num);
    adj.resize(switch_num * 2);

    for (int &state : room_state)
        cin >> state;

    for (int i = 0; i < switch_num; ++i) {
        int cnt, room;
        cin >> cnt;
        while (cnt--) {
            cin >> room;
            connected_switch[room - 1].push_back(i);
        }
    }

    for (int i = 0; i < room_num; ++i) {
        int a = trueX(connected_switch[i][0]);
        int b = trueX(connected_switch[i][1]);
        int not_a = notX(a), not_b = notX(b);

        if (room_state[i] == 0) {
            adj[not_a].push_back(b);
            adj[not_b].push_back(a);
            adj[a].push_back(not_b);
            adj[b].push_back(not_a);
        } else {
            adj[a].push_back(b);
            adj[b].push_back(a);
            adj[not_a].push_back(not_b);
            adj[not_b].push_back(not_a);
        }
    }

    cout << Solve2SAT() << '\n';
    return 0;
}
