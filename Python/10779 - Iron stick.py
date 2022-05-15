iron = input()

ans = 0
value = 0

for i in range(len(iron)):
    cur = iron[i]
    prev = iron[i-1]
    if cur == '(':
        value += 1

    else:
        if prev == '(':
            value -= 1
            ans += value

        else:
            value -= 1
            ans += 1

print(ans)
