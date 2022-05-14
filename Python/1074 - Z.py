# divide and conquer
def solve(n, y, x, result):
    if n == 0:
        return result

    standard = 2 ** (n-1)

    # divide: area 1
    if y < standard and x < standard:
        return solve(n-1, y, x, result)

    # divide: area 2
    elif y < standard <= x:
        result += (standard * standard)
        return solve(n-1, y, x - standard, result)

    # divide: area 3
    elif x < standard <= y:
        result += ((standard * standard) * 2)
        return solve(n-1, y - standard, x, result)

    # divide: area 4
    elif y >= standard and x >= standard:
        result += ((standard * standard)* 3)
        return solve(n - 1, y - standard, x - standard, result)


n, r, c = map(int, input().split())
print(solve(n, r, c, 0))

