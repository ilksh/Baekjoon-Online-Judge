#include<bits/stdc++.h>
using namespace std;

int num[11];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    for(int i= 0 ; i < 10; ++i){
        cin >> num[i];
    }
    
    int s = 0;
    int cmp = 0;

    for(int i = 0; i < 10; ++i){
        cmp += num[i];
        
        int cmpGap = abs(100 - cmp);
        int sGap = abs(100 - s );
            
        if(cmpGap < sGap) s = cmp;
        else if(cmpGap == sGap) s = max(cmp,s);
        
    }
    cout << s;
    return  0;
}
