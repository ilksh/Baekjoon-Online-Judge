from collections import deque


def step1(rst, dq):
    if len(dq) == 0:
        return
    rst.append(dq.popleft())


def step2(dq):
    if len(dq) == 0:
        return
    cur = dq.popleft()
    dq.append(cur)


n = int(input())
temp = [i for i in range(1, n+1)]
ans = []
q = deque(temp)

for _ in range(n):
    step1(ans, q)
    step2(q)

for data in ans:
    print(data, end=" ")