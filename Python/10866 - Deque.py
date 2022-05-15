from collections import deque
import sys
input = sys.stdin.readline

dq = deque()

tc = int(input())

for _ in range(tc):
    s = input().split()
    command = s[0]

    if command == "push_front":
        x = s[1]
        dq.appendleft(x)

    elif command == "push_back":
        x = s[1]
        dq.append(x)

    elif command == "pop_front":
        if dq:
            print(dq.popleft())
        else:
            print(-1)

    elif command == "pop_back":
        if dq:
            print(dq.pop())
        else:
            print(-1)

    elif command == "size":
        print(len(dq))

    elif command == "empty":
        if dq:
            print(0)
        else:
            print(1)

    elif command == "front":
        if dq:
            print(dq[0])
        else:
            print(-1)

    # command == "back"
    else:
        if dq:
            print(dq[-1])
        else:
            print(-1)
