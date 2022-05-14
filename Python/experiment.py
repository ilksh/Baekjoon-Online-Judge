from collections import deque

a = deque()

for i in range(5):
    a.appendleft(i)

print(a)