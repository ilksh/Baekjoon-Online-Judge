s = input()

stack = []
flag = True
value = 1
ans = 0

for i in range(len(s)):
    cur = s[i]
    prev = s[i-1]
    if cur == '(':
        stack.append(cur)
        value *= 2

    elif cur == '[':
        stack.append(cur)
        value *= 3

    elif cur == ')':
        if not stack or stack[-1] == '[':
            flag = False
            break
        if prev == '(':
            ans += value
        stack.pop()
        value //= 2

    else:
        if not stack or stack[-1] == '(':
            flag = False
            break
        if prev == '[':
            ans += value
        stack.pop()
        value //= 3

if stack or not flag:
    print(0)
else:
    print(ans)





