n = int(input())

start = 1
end = n

while end - start > 1:
    mid = (end + start) // 2
    result = mid * mid

    if result > n:
        end = mid

    elif result < n:
        start = mid

    else:
        print(mid)
        break