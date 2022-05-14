n = int(input())
tower = list(map(int, input().split()))
# s= (idx+1, tower[idx])
# using stack, effectively explore tower
# which is higher than the current tower among the towers that locates on the left
s = []

for i in range(n):
    while True:
        # candidate(s) available
        if s:
            # Explore to the left of the present and find a tower higher than the current tower. 
            # pop if the left tower is lower than the current
            if s[-1][1] < tower[i]:
                s.pop()

            else:
                print(s[-1][0], end=" ")
                s.append((i+1, tower[i]))
                break
        # no candidate
        else:
            print(0, end=" ")
            s.append((i+1, tower[i]))
            break
