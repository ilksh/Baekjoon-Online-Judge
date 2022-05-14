def solve(budget, limit, tot):
    temp = 0
    for data in budget:
        # requested budget is lower than the mx budget
        # just plus the request
        if data < limit:
            temp += data
        # requested amount exceeds the upper limit
        else:
            temp += limit

    # temp is lower than the total > increase the limit
    if temp <= tot:
        return True
    # decrease the limit
    else:
        return False


# number of area
n = int(input())

# requested budget for each region
request = list(map(int, input().split()))

# total budget
total = int(input())

request.sort()
# sum of requested budget
r_sum = sum(request)

if r_sum <= total:
    print(request[-1])

else:
    start = 0
    end = request[-1]
    while end - start > 1:
        # mid = upper limit of budget
        mid = (end + start) //2
        if solve(request, mid, total):
            start = mid

        else:
            end = mid

    print(start)
