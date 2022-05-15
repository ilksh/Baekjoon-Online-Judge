from collections import deque

n, m = map(int, input().split())
dq = deque(i for i in range(1, n+1))
target = deque(map(int, input().split()))
cnt = 0

while target:
    if dq[0] == target[0]:
        dq.popleft()
        target.popleft()
        continue

    if dq.index(target[0]) > len(dq) // 2:
        dq.appendleft(dq.pop())

    else:
        dq.append(dq.popleft())
    cnt += 1

print(cnt)

