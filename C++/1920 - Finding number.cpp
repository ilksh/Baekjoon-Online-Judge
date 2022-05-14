#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 1e5 + 1;
int aidx, bidx;
int a[MAX];
int b[MAX];
bool ans[MAX];

bool check(int num)
{
	int start = -1;
	int end = aidx;
	int mid;

	while ((end - start) > 1)
	{
		mid = (end + start) / 2;
		//cout << "mid: " << mid << "\n";

		if (num > a[mid])
			start = mid;

		if (num == a[mid])
		{	
			//cout << "true\n";
			return true;
		}
			

		if (num < a[mid])
			end = mid;
	}
	//cout << "false\n";
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> aidx;
	for (int i = 0; i < aidx; i++)
		cin >> a[i];

	sort(a, a + aidx);
	/*for (int i = 0; i < aidx; i++)
		cout << a[i] << " ";
	cout << "\n";*/

	cin >> bidx;
	for (int i = 0; i < bidx; i++)
	{
		cin >> b[i];
		ans[i] = check(b[i]);
	}

	for (int i = 0; i < bidx; i++)
		cout << ans[i] << "\n";

}