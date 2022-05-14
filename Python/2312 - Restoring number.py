from collections import Counter

# test case
tc = int(input())

for _ in range(tc):
    num = int(input())
    d = 2            # divider
    ans = []
    while d <= num:
        if num % d == 0:
            num //= d
            ans.append(d)

        else:
            d += 1

    n_ans = Counter(ans)
    for keys, values in n_ans.items():
        print("{} {}".format(keys, values), end = "\n")


