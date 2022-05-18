import sys

sys.setrecursionlimit(10**5)

n, m = map(int, input().split())
par = [i for i in range(n+1)]

def union(a, b):
    a = find(a)
    b = find(b)

    par[a] = b

def find(x):
    if par[x] == x:
        return x

    par[x] = find(par[x])
    return par[x]

for _ in range(m):
    q, a, b = map(int, input().split())
    if q == 0:
        union(a, b)
    else:
        print('YES' if find(a) == find(b) else 'NO')