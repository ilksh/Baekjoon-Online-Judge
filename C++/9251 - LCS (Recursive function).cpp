#include<iostream>
#include<string.h>
using namespace std;
const int MAX_N = 1001;
int cache[MAX_N][MAX_N];
string str1;
string str2;

int n; //len(str1)
int m; //len(str2)

//ACAYKP
//CAPCAK

int solve(int idx1, int idx2)
{	
	if (idx1 == n || idx2 == m)
		return 0;

	int& result = cache[idx1][idx2];
	
	if (result != -1)
		return result;

	if (str1[idx1] == str2[idx2])
		result = 1 + solve(idx1 + 1, idx2 + 1);

	if (str1[idx1] != str2[idx2])
		result = max(solve(idx1 + 1, idx2), solve(idx1, idx2 + 1));

	return result;
}
int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(cache, -1, sizeof(cache));

	cin >> str1;
	cin >> str2;

	n = str1.size();
	m = str2.size();
	/*cout << n << "\n";
	cout << m<<"\n";*/

	cout << solve(0, 0);




}