# store changes in ants' arrangements every second
ans = []

# input data
n1, n2 = map(int, input().split())
left = list(input())
right = list(input())
t = int(input())

# mn =
mn = min(n1, n2)
left = left[::-1]
# if t equals to 0, there's no change on the arrangements
ans.append("".join(left)+"".join(right))


def swap(idx1, idx2):
    if idx1 >= 0 and idx2 >= 0:
        temp = right[idx1]
        right[idx1] = right[idx2]
        right[idx2] = temp

    elif idx1 >= 0 and idx2 < 0:
        temp = right[idx1]
        right[idx1] = left[idx2]
        left[idx2] = temp

    elif idx1 < 0 and idx2 >= 0:
        temp = right[idx2]
        right[idx2] = left[idx1]
        left[idx1] = temp

    else:
        temp = left[idx1]
        left[idx1] = left[idx2]
        left[idx2] = temp


# Out Of Range
def oor(num):
    if num > n2-1 or num < -n1:
        return True
    return False


"""
Cycle 1
1.1)
-> Cycle 1 repeats until the rightmost ant of the left array reaches to the rightmost index of the right array.
-> Thus, Cycle 1 repeats n2 (the number of ants in rights array) times.

1.2)
-> During Cycle 1, the leftmost ant (an ant with an initial index of -1) starts moving,
-> and the starting index decreases by -2).

1.3)
-> The maximum number of times, which ants can swap per second, reflects the fewer numbers of array left or right.
-> The situation is managed by variable mn and cnt
"""
# 1.1)
for cyc1 in range(n2):
    # 1.2)
    s = cyc1 -1
    cnt = 0
    for j in range(cyc1+1):
        cnt += 1
        # 1.3)
        if cnt > mn:
            continue
        if oor(s) or oor(s+1):
            continue
        swap(s, s+1)
        s -= 2
    rst = "".join(left)+"".join(right)
    ans.append(rst)


# Cycle 2
"""
Cycle 2
2.1)
-> Cycle 2 is executed after new data is transferred to the right side of the right array.
-> Thus, the Cycle 2 repeats (n1 -1) times.

2.2)
During Cycle 2, starting with the second arrangement to the right of the right array (index with n2 -2),
the starting index decreases by 2 as in Cycle 1.

2.3)
The maximum number of times, which ants can swap per second, are the same as Cycle 1
"""
# 2.1)
for cyc2 in range(n1-1):
    # 2.2)
    s = n2-2-cyc2
    cnt = 0
    for _ in range(n1-1-cyc2):
        cnt += 1
        # 2.3)
        if cnt > mn:
            continue
        if oor(s) or oor(s-1):
            continue
        swap(s, s-1)
        s -= 2

    rst = "".join(left) + "".join(right)
    ans.append(rst)

# prevent if t exceeds maximum time ants able to swap
t = min(n1+n2-1, t)
# print the arrangement of ants after t seconds
print(ans[t])



