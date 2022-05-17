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
    # allow overlap and the condition changed
    for i in range(num, n+1):
        stack.append(i)
        bt(i)
        stack.pop()


bt(1)