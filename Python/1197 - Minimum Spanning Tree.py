def find(x):
    global par

    if par[x] == -1:
        return x

    par[x] = find(par[x])

    return par[x]


def union(a, b):
    a = find(a)
    b = find(b) 

    if a == b:
        return

    par[a] = b


n, m = map(int, input().split())
par = [-1 for i in range(n+1)]
edge_list = []
mst = 0
for _ in range(m):
    u, v, w = map(int, input().split())
    edge_list.append((w,u,v))

edge_list.sort()

for w, u, v in edge_list:
    if find(u) != find(v):
        mst += w
        union(u, v)

print(mst)