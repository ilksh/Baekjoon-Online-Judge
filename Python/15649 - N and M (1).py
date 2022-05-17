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
    # complete of the sequence without allowing overlap
    # and keeping the number of data from 1 to n below m
    for i in range(1, n+1):
        if i not in stack:
            stack.append(i)
            bt()
            stack.pop()


bt()
"""
===
1 2
1 3
1 4
===
start a new node using stack.pop 
because we used up to number n
===
2 1
2 3
2 4
"""