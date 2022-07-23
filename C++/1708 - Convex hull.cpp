#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point{
    ll x, y;    // x, y coordinate
    
    // redefine operator <
    bool operator < (const Point& rhs)const{
        if(x!= rhs.x)
            return x < rhs.x;
        return y < rhs.y;
    }
};

const int MAX_N = 1e5 + 5;
int n;  // number of points

Point point[MAX_N];

// counter clock wise
int ccw(Point& p1, Point& p2, Point& p3)
{
    // a·b = x2*y1 - x1*y2 = (x3-x1)*(y2-y1) - (x2-x1)*(y3-y1)
    ll ret = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - (p1.x*p3.y + p2.x*p1.y + p3.x*p2.y);
    
    if(ret > 0) return 1;   // ccw
    if(ret < 0) return -1;  // cw
    return 0;               // parallel
}

ll getDist(Point& p1, Point& p2)
{
    ll ret = (p1.x-p2.x) * (p1.x-p2.x) + (p1.y- p2.y)*(p1.y- p2.y);

    return ret;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0; i<n; ++i){
        cin >> point[i].x >> point[i].y;
    }
    
    // to find leftmost point
    sort(point, point+n);
    
    // 1. sort points with angle as a priority
    // 2. sort points from p[0] to closer order
    sort(point+1, point+n, [](Point& p1, Point& p2){
        int ret = ccw(point[0], p1, p2);
        // step 1
        if(ret!= 0)
            return ret > 0;
        // step 2
        return getDist(point[0], p1) < getDist(point[0], p2);
    });
    
    vector<Point> v;
    
    for(int i=0; i<n; ++i){
        while(v.size()>= 2 && ccw(v[v.size()-2], v[v.size()-1],point[i]) <=0){
            v.pop_back();
        }
        
        v.push_back(point[i]);
    }
    
    cout << v.size() << "\n";
    
    return 0;
}

