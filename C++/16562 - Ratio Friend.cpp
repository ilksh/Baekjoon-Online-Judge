#include <bits/stdc++.h> 

using namespace std;

const int MAX_M = 1e4 + 4;

int arr[MAX_M];
int par[MAX_M];
bool visited[MAX_M];

int find(int x) {
	if (par[x] < 0) return x;
	return par[x] = find(par[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (arr[a] < arr[b]) par[b] = a;
	else par[a] = b;
}

int main(void){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)  cin >> arr[i];
	
	memset(par, -1, sizeof(par));

	for (int i = 0; i < m; ++i) {
		int v, w;
		cin >> v >> w;
		merge(v, w);
	}

	int ans = 0;

	for (int i = 1; i < n + 1; ++i) {
		int root = find(i);
		if (root == -1) {
			visited[root] = true;
			ans += arr[root];
			continue;
		}

		if (visited[root]) continue;
		visited[root] = true;
		ans += arr[root];
	}

	if (ans > k) cout << "Oh no";
	else cout << ans;

	return 0;
}
