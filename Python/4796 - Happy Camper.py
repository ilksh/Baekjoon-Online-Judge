case_idx = 1
ans = []
while True:
    # L days within any consecutive P-day period.
    # Happy Camper Harry is just starting a V-day vacation.
    l, p, v = map(int, input().split())
    if l == 0 and p == 0 and v == 0:   # End of data will be signaled by a line containing three zeros
        break
    quotient = v // p
    remain = (v %p) if (v % p) <= l else l

    s = l * quotient + remain
    ans.append("Case {}: {}".format(case_idx, s))
    case_idx += 1

for elem in ans:
    print(elem)