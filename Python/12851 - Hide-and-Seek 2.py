from collections import deque


def in_range(num):
    if 0 <= num <= MAX_N:
        return True
    return False


MAX_N = 100001
dq = deque()
dist = [-1 for _ in range(MAX_N+1)]
# visited = [False for _ in range(MAX_N +1)]
# this problem doesn't need variable visited
# not only find the shortest time,
# but we need to find the number of cases in the shortest time,
# avoid omitting the case, which arrive in the shortest time through different routes
n, k = map(int, input().split())
dq.append(n)
dist[n] = 0
cnt = 0

while dq:
    cur = dq.popleft()
    if cur == k:
        cnt += 1

    candidate = [cur-1, cur+1, cur*2]
    for nxt in candidate:
        if in_range(nxt):
            # if the value of dist is not renewed
            if dist[nxt] == -1 or dist[nxt] >= dist[cur]+1:
                dist[nxt] = dist[cur] + 1
                dq.append(nxt)

print(dist[k])
print(cnt)
