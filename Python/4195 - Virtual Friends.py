import sys

sys.setrecursionlimit(10**5)

t = int(input())


def union(a, b):
    a = find(a)
    b = find(b)

    if a != b:
        par[a] = b
        cnt[b] += cnt[a]


def find(x):
    if par[x] == x:
        return x

    par[x] = find(par[x])
    return par[x]


for _ in range(t):
    f = int(input())
    par = dict()
    cnt = dict()
    for _ in range(f):
        a, b = input().split()
        if a not in cnt.keys():
            cnt[a] = 1
            par[a] = a
        if b not in cnt.keys():
            cnt[b] = 1
            par[b] = b

        union(a, b)
        print(cnt[find(a)])




