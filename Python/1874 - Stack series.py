n = int(input())

# array that contains number
arr = []
ans = []
flag = True
num = 0

for _ in range(n):
    cur = int(input())
    # Data input process
    while num < cur:
        num += 1
        arr.append(num)
        ans.append('+')

    # if end of the array equals to current value
    if arr[-1] == cur:
        arr.pop()
        ans.append('-')

    else:
        # unable to create entered sequence
        flag = False

if not flag:
    print("NO")

else:
    for sign in ans:
        print(sign)