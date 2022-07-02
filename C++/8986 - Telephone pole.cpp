#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 1e5 + 1;

ll n;   //number of pole
ll pole[MAX_N];

ll calc(ll pos)
{
    ll s = 0;
    
    for(int i=1; i< n; i++)
        s += abs(pos * i - pole[i]);
    
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> pole[i];
    
    if(n ==1)
    {
        cout << 0;
        return 0;
    }
    
    ll mn = 0;
    ll mx = pole[n-1];
   
    while ((mx - mn) >= 3)
    {
        ll temp1 = (mn * 2 + mx) / 3;
        ll temp2 = (mn + mx *2) / 3;
        
        if(calc(temp1) < calc(temp2)){
            mx = temp2;
        }
        
        else {
            mn = temp1;
        }
    }
    
    ll ans = 1e15;
    
    for(auto i= mn; i< mx + 1; i++)
        ans = min(ans, calc(i));
    
    cout << ans;
    return 0;
}
