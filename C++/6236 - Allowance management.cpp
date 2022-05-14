#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int lli;
const int MAX_N = 1e5 + 1;
lli money[MAX_N];
int n, m;

bool check(lli num)
{
    lli imsi = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        imsi += guitar[i];

        if (imsi > num)
        {
            cnt++;
            imsi = money[i];
        }

    }
   // cout << "cnt: " << cnt << "\n";

    if (cnt >= m)
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;

    lli total = 0;
    lli  max_time = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> money[i];
        total += money[i];
        max_time = max(money[i], max_time);
    }

    lli start = max_time;
    lli end = total + 1;
    lli mid;

    while (start <= end)
    {
        mid = (end + start) / 2;
        /*cout << "start: " << start << "\n";
        cout << "mid: " << mid << "\n";
        cout << "end: " << end << "\n";*/

        if (check(mid))
            start = mid+1;
        else
            end = mid-1;

       // cout << "========\n";
    }

    cout << start;
    return 0;
}