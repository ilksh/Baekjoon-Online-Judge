n, m = map(int, input().split())

dict1 = {}  # name: idx
dict2 = {}  # idx : name
ans = []

idx = 1
for _ in range(n):
    name = input()
    dict1[name] = idx
    dict2[idx] = name
    idx += 1

for _ in range(m):
    cmd = input()
    # if cmd can be inverted to integer
    try:
        cmd = int(cmd)
    # cmd is string
    except Exception as e:
        ans.append(dict1[cmd])
        continue

    ans.append(dict2[cmd])

for data in ans:
    print(data)