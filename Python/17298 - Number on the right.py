n = int(input())
data = list(map(int, input().split()))
stack = []
# initialize ans with -1
# for the case that has no bigger number on the right
ans = [-1 for _ in range(n)]

# step 1) explore the entire data: safe
#         time complex = n
for i in range(n):
    # step 2) avoid brute forcing
    #         explore the rest of data that have not answered
    #         using stack -> explore direction: left to right
    while stack and data[stack[-1]] < data[i]:
        ans[stack.pop()] = data[i]
    stack.append(i)

for elem in ans:
    print(elem, end=" ")


"""
- Find the solution through Brute Forcing
- Flaw: timeout -> worst time complex is around 2 * 1e9

def check(arr):
    for e in arr:
        if e > cur:
            print(e, end=" ")
            return
    print(-1, end=" ")

for i in range(n-1):
    cur = data[i]
    check(data[i+1: n])

print(-1)
"""