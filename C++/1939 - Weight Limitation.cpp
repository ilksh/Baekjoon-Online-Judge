#include<bits/stdc++.h>
#define MAXP    1000000000LL
using namespace std;


struct Link
{
    Link(int a,int b):to(a),p(b){}
    int to, p;
};

int main()
{
    int n, m, start, end;
    static int nodes[10000];
    std::vector<Link> links[10000];
    std::priority_queue<long long> queue;
    scanf("%d%d", &n, &m);
    while(m--)
    {
        int s, t, p;
        scanf("%d%d%d", &s, &t, &p);
        links[s-1].push_back(Link(t-1,p));
        links[t-1].push_back(Link(s-1,p));
    }
    scanf("%d%d", &start, &end); start--; end--;
    queue.push(MAXP<<32 | start);
    for(;;)
    {
        int p = queue.top() >> 32;
        int s = queue.top() & 0xffffffff;
        queue.pop();
        if(s == end) break;
        for(auto &t:links[s])
        {
            int np = t.p < p ? t.p : p, to = t.to;
            if(np > nodes[to])
            {
                nodes[to] = np;
                queue.push(((long long)np) << 32 | to);
            }
        }
    }
    printf("%d\n", nodes[end]);
}