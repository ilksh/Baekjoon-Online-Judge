# step1: input
# s = 1+2-3+4-5+6

# step2: split based on '-'
# (1+2)-(3+4)-(5+6)
# s = ["1+2", "3+4", "5+6"]

s = input().split('-')

# step3: add the first part
# ans += 1, ans+=2
ans = 0
isFirst = True

for substr in s:
    temp = 0
    for num in substr.split('+'):
        temp += int(num)
    if isFirst:
        ans += temp
        isFirst = False
    else:
        ans -= temp

print(ans)