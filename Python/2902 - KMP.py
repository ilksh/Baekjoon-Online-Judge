string = input().split('-')
ans = []
for name in string:
    ans.append(name[0])
print("".join(ans))
