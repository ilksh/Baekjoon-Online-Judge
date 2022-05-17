n, m = map(int, input().split())

stack = []


# Back Tracking
def bt():
    # print answer
    if len(stack) == m:
        for elem in stack:
            print(elem, end=" ")
        print("")
        return
    # allow overlap
    for i in range(1, n+1):
        stack.append(i)
        bt()
        stack.pop()


bt()