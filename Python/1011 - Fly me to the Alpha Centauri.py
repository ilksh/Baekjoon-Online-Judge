def check(x, y):
    d = y - x
    n = 1
    while 1:
        if n**2 <= d < (n+1)**2:
            break
        n += 1

    if n ** 2 == d:
        print(n * 2 - 1)
    elif (n ** 2) < d <= (n ** 2) + n:
        print(n * 2)
    else:
        print(n * 2 + 1)


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        x, y = map(int, input().split())
        check(x, y)
