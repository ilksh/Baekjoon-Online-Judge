def check (num):
    global x, y, z
    ny = y + num
    nx = x + num
    nz = int((ny * 100/nx))

    if nz > z:
        return True

    else:
        return False


# total, winning
x, y = map(int, input().split())
z = int((y * 100 / x))

# unable to increase the winning prob of 99% and 100%
if z >= 99:
    print(-1)

else:
    start = 0
    end = x

    # Check the number of times to increase the winning prob
    # using the binary search
    while(end - start > 1):
        mid = (end + start) // 2
        # reduce the range
        if check(mid):
            end = mid

        else:
            start = mid

    print(end)





