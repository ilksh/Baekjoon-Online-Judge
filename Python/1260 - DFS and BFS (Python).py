from collections import deque

# number of vertices, edges and start
n, m, start = map(int, input().split())

arr = [[False] * (n+1) for _ in range(n+1)]
visited = [False] * (n+1)
q = deque()

for _ in range(m):
    v1, v2 = map(int, input().split())
    arr[v1][v2] = arr[v2][v1] = True


def dfs(num):
    visited[num] = True
    print(num, end=" ")
    for i in range(1, n+1):
        if not visited[i] and arr[num][i] is True:
            dfs(i)


def bfs(num):
    q.append(num)
    visited[num] = True

    while len(q) > 0:
        cur = q.popleft()
        print(cur, end=" ")
        for i in range(1, n+1):
            if not visited[i] and arr[cur][i] is True:
                visited[i] = True
                q.append(i)


dfs(start)
visited = [False] * (n+1)
print("")
bfs(start)










