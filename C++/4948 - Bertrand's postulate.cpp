#include<iostream>
#include<queue>
using namespace std;
const int MAX_N = 2 * 123456 + 1;
bool deleted[MAX_N];
queue<int> ans;

void eratosthenes() 
{
    for (int i = 2; i <= MAX_N; i++)
    {
        if (deleted[i])
            continue;

        for (int j = i + i; j <= MAX_N; j += i)
        {
            deleted[j] = true;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    eratosthenes();

    while (true)
    {
        int num;
        cin >> num;
        if (num == 0)
            break;

        int cnt = 0;
        for (int i = num+1; i <= 2 * num; i++)
        {
            if (!deleted[i])
                cnt++;
        }
        ans.push(cnt);
    }

    while (!ans.empty())
    {
        int cur = ans.front(); ans.pop();
        cout << cur << "\n";
    }
}