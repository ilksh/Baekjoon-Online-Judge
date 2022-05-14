# generator of 'sum' is 'num'
# thus, sum should not be self-number which has no generator
def check(num):
    sum = num
    while num > 0:
        sum += num % 10
        num //= 10

    return sum


# True = the number is self number
self_num = [True for _ in range(10001)]

for idx in range(1, 10001):
    rst = check(idx)
    # rst has a generator
    # rst is not a self number
    if rst < 10001:
        self_num[rst] = False

for idx in range(1, 10001):
    if self_num[idx] is True:
        print(idx)