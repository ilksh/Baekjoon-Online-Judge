n, m = map(int, input().split())

# key = site, value = pw
data = {}
for _ in range(n):
    site, pw = input().split()
    data[site] = pw

ans = []

for _ in range(m):
    target = input()
    print(data[target])