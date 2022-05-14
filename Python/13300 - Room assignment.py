import sys
input = sys.stdin.readline

def room_check(student, k):
    cnt = 0
    for i in range(1, 7):
        while student[i] > 0:
            student[i] -= k
            cnt += 1
    return cnt


male = [0 for _ in range(7)]
female = [0 for _ in range(7)]

n, k = map(int, input().split())

for _ in range(n):
    # gender and grade
    s, y = map(int, input(). split())

    if s == 0:
        female[y] += 1

    else:
        male[y] += 1

ans = room_check(female, k) + room_check(male, k)
print(ans)