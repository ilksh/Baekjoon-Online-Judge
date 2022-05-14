# store changes in ants' arrangements every second
ans = []
# input data
n1, n2 = map(int, input().split())
left = list(input())
left = left[::-1]
right = list(input())
t = int(input())

for ch in left:
    ans.append((ch, 1))

for ch in right:
    ans.append((ch, 0))

skip = False
for iter in range(t):
    for i in range(n1 + n2 - 1):
        if skip:
            skip = False
            continue
        if ans[i][1] != ans[i+1][1]:
            ans[i], ans[i+1] = ans[i+1], ans[i]
            skip = True

for tp in ans:
    print(tp[0], end="")