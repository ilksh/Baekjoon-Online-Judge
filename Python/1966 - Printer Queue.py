from collections import deque


def mx_find(queue):
    mx = -1
    for data, idx in queue:
        mx = max(mx, data)
    return mx


tc = int(input())  # test case

for _ in range(tc):
    n, m = map(int, input().split())
    temp = list(map(int, input().split()))
    dq = deque()     # priority, idx

    for i in range(len(temp)):
        dq.append((temp[i], i))

    cnt = 0
    while dq:
        cur_val, cur_idx = dq[0]
        # 1. process the highest priority task
        if cur_val == mx_find(dq):
            dq.popleft()
            cnt += 1
            # 2. check the targeted index
            if cur_idx == m:
                print(cnt)

        else:
            dq.append(dq.popleft())
