num = 64
d = {}
# key = length of stick, value = number of stick
# d = {64: 1, 32: 2, 16: 4, 8: 8, 4: 16, 2: 32, 1: 64}
while num >= 1:
    d[num] = 64//num
    num //= 2


x = int(input())
cnt = 0
for keys in d.keys():
    # use the stick which is shorter or equals to x
    # while the number of the stick is sufficient
    while keys <= x and d[keys] > 0:
        x -= keys
        cnt += 1

print(cnt)

