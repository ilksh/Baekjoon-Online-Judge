#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<pii> v;
double ans;

int numOfLine; // number of line

ll crossProd(pll v1, pll v2) { // cross product of two vectors
    return v1.first * v2.second - v1.second * v2.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> numOfLine;
    
    for(int i = 0 ; i < numOfLine; ++i) {
        int x, y; // x coordinate, y coordinate
        cin >> x >> y;
        v.push_back({x, y});
    }
    
    for(int i = 1 ; i < numOfLine - 1; ++i) {
        ll v1First = v[i].first - v[0].first;           // change of x in vector 1
        ll v1Second = v[i].second - v[0].second;        // change of y in vector 1
        ll v2First = (v[i + 1].first - v[0].first);     // change of x in vector 2
        ll v2Second = (v[i + 1].second - v[0].second);  // change of y in vector 2
        pll v1 = {v1First, v1Second};
        pll v2 = {v2First, v2Second};
        auto temp = (crossProd(v1, v2) / 2.0);          // calculate the area with cross product
        ans += temp;
    }
    
    ans = abs(ans);
    
    printf("%.1lf",ans);
    return 0;
}

