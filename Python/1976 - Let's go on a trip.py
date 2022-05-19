import sys

sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n = int(input())
parent = [i for i in range(n + 1)]


def union(a, b):
    a = find(a)
    b = find(b)

    if a != b:
        parent[a] = b


def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]


if __name__ == '__main__':
    m = int(input())
    for i in range(n):
        city = list(map(int, input().split()))
        for j in range(n):
            if i == j:
                continue

            if city[j] == 1:
                union(i + 1, j + 1)

    route = list(map(int, input().split()))
    standard = find(route[0])
    flag = True
    for elem in route:
        if find(elem) != standard:
            flag = False
            break

    if flag:
        print("YES")
    else:
        print("NO")

