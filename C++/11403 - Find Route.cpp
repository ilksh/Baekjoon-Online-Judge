#include<bits/stdc++.h>

using namespace std;

int n; // number of node
const int MAX_N = 1e2 + 2;
bool arr[MAX_N][MAX_N]; 
vector<int> adj[MAX_N]; // adjacent matrix 


vector<bool> solve(int start) {
    vector<bool> visited (n + 1, false);
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int e : adj[cur]) {
            if (!visited[e]) {
                q.push(e);
                visited[e] = true;
            }
        }
    }
    return visited;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            cin >> arr[i][j];
            if (arr[i][j]) adj[i].push_back(j);
        }
    } 
    vector< vector <bool> > rst;

    for (int start = 1; start < n + 1 ; ++start) {
        
        vector<bool> temp  = solve(start);
        rst.push_back(temp);
    }

    for (vector<bool> vec : rst) {
        for (int i = 1; i < n + 1; ++i) {
            if (vec[i]) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << "\n";
    }

    return 0;
}
