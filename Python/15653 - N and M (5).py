n, m = map(int, input().split())
data = list(map(int, input().split()))
data.sort()
stack = []
visited = [False for _ in range(n)]


# Back Tracking
def bt(idx):
    # print answer
    if idx == m:
        for elem in stack:
            print(elem, end=" ")
        print("")
        return
    # allow overlap and the condition changed
    for i in range(n):
        if not visited[i]:
            stack.append(data[i])
            visited[i] = True
            bt(idx+1)
            stack.pop()
            visited[i] = False


bt(0)