n, m = map(int, input().split())

stack = []


# Back Tracking
def bt(num):
    # print answer
    if len(stack) == m:
        for elem in stack:
            print(elem, end=" ")
        print("")
        return
    # complete of the sequence without allowing overlap
    for i in range(num, n + 1):
        if i not in stack:
            stack.append(i)
            # ascending order
            bt(i + 1)
            stack.pop()


bt(1)
