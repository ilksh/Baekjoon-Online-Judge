l = int(input())
string = input()
ans = 0
# exponent
exp = 0

for char in string:
    ans += (ord(char) - 96) * (31**exp)
    exp += 1
    ans %= 1234567891

print(ans)
