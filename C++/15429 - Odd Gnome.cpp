#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;  // {number, index}

int n, gnome;
vector<pii> v;
  
void solve()
{
    for(int i=2; i <n; ++i)
    {
        auto prev = v[i-2];
        auto cur = v[i-1];
        auto nxt = v[i];
        
        int diff1 = cur.first  - prev.first;
        int diff2 = nxt.first - cur.first;
        
        // three consecutive numbers are not continuous
        if(diff1 != 1 and diff2 != 1)
        {
            cout << cur.second <<"\n";
            return;
        }
            
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while(tc--)
    {
        cin >> n;
        v.clear(); // initialzie vector
        
        for(int i=0; i<n; ++i)
        {
            cin >> gnome;
            v.push_back({gnome, i+1});
        }
        
        solve();
    }
    
    return 0;
}
