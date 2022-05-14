# test case
tc = int(input())
ans = []
for i in range(tc):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    b.sort()

    cnt = 0

    for data in a:
        start = 0
        end = m
        while end > start:
            mid = (start + end) // 2

            if data <= b[mid]:
                end = mid
            else:
                start = mid + 1
        cnt += start
    ans.append(cnt)

for num in ans:
    print(num)





