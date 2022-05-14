n = int(input())
condo = [input() for i in range(n)]
condo2 = []

for i in range(n):         # transform
    temp = ''
    for j in range(n):
        temp += condo[j][i]
    condo2.append(temp)

horizon = 0
vertical = 0

# horizontal check
for row in condo:
    for seat in row.split('X'):
        if len(seat) >= 2:
            horizon += 1

# vertical check
for col in condo2:
    for seat in col.split('X'):
        if len(seat) >= 2:
            vertical += 1

print(horizon, vertical)