def bt(y):  # back tracking
    global n, ans, col, dia1, dia2

    # base case: end of the row
    if y == n:
        ans += 1
        return

    for x in range(n):
        # no overlap in either direction
        # deploy queen
        if col[x] is False and dia1[x+y] is False and dia2[x-y+n-1] is False:
            col[x] = True
            dia1[x+y] = True
            dia2[x-y+n-1] = True

            bt(y+1)

            # backtracking
            col[x] = False
            dia1[x + y] = False
            dia2[x - y + n - 1] = False


n = int(input())
ans = 0
# determine if it is in the same column
col = [False for _ in range(n)]
# determine if it is in the same diagonal whose slope is positive
dia1 = [False for _ in range(2*n)]
# determine if it is in the same diagonal whose slope is positive
dia2 = [False for _ in range(2*n)]

bt(0)
print(ans)

