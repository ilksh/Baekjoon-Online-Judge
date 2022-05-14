#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
vector <pii> v;
queue<pii> answer;
int cur_time;
int cnt;

bool cmp(pii& a, pii& b)
{
	if (a.second != b.second)
		return a.second < b.second;

	return a.first < b.first;
}

int main()
{
	int test_case;
	cin >> test_case;

	v.resize(test_case);
	for (int i = 0; i < test_case; i++)
		cin >> v[i].first >> v[i].second;
	
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < test_case; i++)
	{
		if (cur_time <= v[i].first)
		{
			cur_time = v[i].second;
			cnt++;
		}
	}
	
	cout << cnt;
	
}