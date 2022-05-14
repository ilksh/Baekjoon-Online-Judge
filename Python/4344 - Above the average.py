import statistics

tc = int(input())

for i in range(tc):
    arr = list(map(int, input().split()))
    num = arr[0]
    arr.pop(0)
    avg = statistics.mean(arr)
    cnt = 0
    for data in arr:
        if data > avg:
            cnt += 1
    ans = (cnt/num) * 100
    print("%.3f" % ans + "%")



