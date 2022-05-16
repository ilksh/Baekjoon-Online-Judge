from collections import deque

a, b = map(int, input().split())
q = deque()
q.append((a, 0))

flag = False

while q:
    cur_val, time = q.popleft()
    if cur_val > b:
        continue
    if cur_val == b:
        print(time+1)
        flag = True
        break
    q.append((cur_val * 10 + 1, time+1))
    q.append((cur_val * 2, time+1))

if not flag:
    print(-1)
