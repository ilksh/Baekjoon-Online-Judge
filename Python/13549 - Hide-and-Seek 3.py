from collections import deque
import sys

input = sys.stdin.readline

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
visited[n] = True

while dq:
    cur = dq.popleft()

    if in_range(cur*2) and not visited[cur*2]:
        visited[cur*2] = True
        dq.appendleft(cur*2)
        dist[cur*2] = dist[cur]

    if in_range(cur+1) and not visited[cur+1]:
        visited[cur+1] = True
        dq.append(cur+1)
        dist[cur+1] = dist[cur] + 1

    if in_range(cur-1) and not visited[cur-1]:
        visited[cur - 1] = True
        dq.append(cur - 1)
        dist[cur - 1] = dist[cur] + 1

print(dist[k])

