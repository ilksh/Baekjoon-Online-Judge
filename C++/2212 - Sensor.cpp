#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int position[10001];
int dist[10000];
vector <int> gap;

int main()
{
	int n; // number of sensor
	cin >> n;
	int k; 	
	cin >> k;
	for (int i = 0; i < n; i++)
		cin >> position[i];
	sort(position, position + n);
	
	for (int i = 0; i < n-1; i++)
		dist[i] = position[i + 1] - position[i];

	sort(dist, dist + (n - 1));
	int ans = 0;
	
	for (int i = 0; i < n - k; i++)
		ans += dist[i];
	cout << ans;

}