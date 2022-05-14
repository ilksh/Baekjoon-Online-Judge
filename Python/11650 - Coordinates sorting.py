n = int(input())

coord = []
for i in range(n):
    x, y = map(int, input().split())
    coord.append((x,y))

coord.sort()

for x,y in coord:
    print(x, y)
