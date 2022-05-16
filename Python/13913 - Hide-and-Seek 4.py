from collections import deque


def in_range(num):
    if 0 <= num <= MAX_N:
        return True
    return False


MAX_N = 100001
dq = deque()

visited = [False for _ in range(MAX_N+1)]
dist = [0 for _ in range(MAX_N+1)]

n, k = map(int, input().split())

dq.append(n)
route = {n: -1}
visited[n] = True

# search
while dq:
    # dq.append = set the new start
    cur = dq.popleft()
    if cur == k:
        break

    if in_range(cur+1) and not visited[cur+1]:
        visited[cur+1] = True
        dq.append(cur+1)
        dist[cur + 1] = dist[cur] + 1
        route[cur + 1] = cur

    if in_range(cur-1) and not visited[cur-1]:
        visited[cur - 1] = True
        dq.append(cur - 1)
        dist[cur - 1] = dist[cur] + 1
        route[cur - 1] = cur

    if in_range(cur*2) and not visited[cur*2]:
        visited[cur*2] = True
        dq.appendleft(cur*2)
        dist[cur * 2] = dist[cur] + 1
        route[cur*2] = cur

print(dist[k])

cur = k
ans = deque()
ans.appendleft(k)

# printing the route from end to start
# 17 -> 16 -> 8 -> 4 -> 5 (o)
# 5 -> 4 -> 8 -> 16 -> 17 (x)
while cur != -1:
    prev = route[cur]
    ans.appendleft(prev)
    cur = prev
ans.popleft()
for data in ans:
    print(data, end=" ")

