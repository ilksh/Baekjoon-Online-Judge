#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N = 51;
int n; 
int m; 
int l; 
int position[MAX_N];

bool check(int num)
{
	int cnt = 0;
	for (int i = 0; i <= n; i++)
		cnt += (position[i + 1] - position[i]-1) / num;

	//cout << "cnt: " << cnt << "\n";

	if (cnt > m)
		return true;

	return false;
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> l;
	position[0] = 0;
	position[n + 1] = l;

	for (int i = 1; i <= n; i++)
		cin >>position[i];
		
	sort(position, position + n+1);

	/*for (int i = 0; i <= n + 1; i++)
		cout << position[i] << " ";
	cout << "\n";*/


	int start = 0;
	int mid;
	int end = l;

	while ((end - start) > 1)
	{
		mid = (end + start) / 2;
		//cout << "mid: " << mid << "\n";

		if (check(mid))
			start = mid;
		else
			end = mid;
	}

	cout << end;

	
}