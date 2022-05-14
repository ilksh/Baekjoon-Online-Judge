def solve(a_idx, b_num):
    global a
    
    if a[a_idx] > b_num:
        return 1

    if a[a_idx] == b_num:
        return 0

    else:
        return -1


n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

a.sort()

# a:  [-10, 2, 3, 6, 10]
# b:  [10, 9, -5, 2, 3, 4, 5, -10]



ans = []

for idx in range(m):
    start = -1
    end = n
    flag = False

    while(end - start > 1):
        mid = (start + end) // 2
        result = solve(mid, b[idx])
        
        # reduce idx
        if result == 1:
            end = mid

        # increase idx
        elif result == -1:
            start = mid
        
        # find the number
        else:
            ans.append(1)
            flag = True
            break
    
    # after the whole search, couldn't find the number
    if not flag:
        ans.append(0)

for data in ans:
    print(data, end= " ")




