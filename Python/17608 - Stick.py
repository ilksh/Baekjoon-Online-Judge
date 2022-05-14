from collections import deque

n = int(input())

dq = deque([])
for i in range(n):
    data = int(input())
    dq.appendleft(data)

standard = dq[0]
dq.popleft()
cnt = 1
for n in dq:
    if standard < n:
        standard = n
        cnt += 1
        
print(cnt)



