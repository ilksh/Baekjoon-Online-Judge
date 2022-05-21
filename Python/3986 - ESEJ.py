from collections import deque
n = int(input())

cnt = 0
for _ in range(n):
    stack = []
    word = deque(input())
    stack.append(word.popleft())
    flag = True
    for elem in word:
        if not stack or stack[-1] != elem:
            stack.append(elem)

        else:
            stack.pop()

    if not stack:
        cnt += 1

print(cnt)


