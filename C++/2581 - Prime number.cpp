#include<iostream>
using namespace std;

const int MAX_N = 1e4 + 1;
bool deleted[MAX_N];
int n, m;
long long int sum;
int ans = 987654321;

void eratosthenes(int num)
{
    for (int i = 2; i <= num; i++)
    {
        if (deleted[i])
            continue;

        for (int j = i + i; j <= num; j += i)
        {
            deleted[j] = true;
        }

    }
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	cin >> m;

    eratosthenes(m);
    int cnt = 0;

    for (int idx = n; idx <= m; idx++)
    {
        if (!deleted[idx] && idx!= 1)
        {
            sum += idx;
            ans = min(ans, idx);
            //cout << "idx: " << idx << "\n";
            cnt++;
        }
    }
    
    if (cnt == 0)
        cout << -1;
    else
        cout << sum << "\n" << ans;

}