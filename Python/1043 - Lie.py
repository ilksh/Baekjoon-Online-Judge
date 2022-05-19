import sys
from collections import deque
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

n, m = map(int, input().split())    # number of ppl and party
par = [i for i in range(n+1)]       # initialize


def union(a, b):
    a = find(a)
    b = find(b)

    if a != b:
        par[a] = b


def find(x):
    if par[x] == x:
        return x

    par[x] = find(par[x])
    return par[x]


if __name__ == '__main__':
    truth = deque(map(int, input().split()))
    if len(truth) <= 1:
        print(m)
    else:
        truth.popleft()

        for i in range(len(truth) - 1):
            union(truth[i], truth[i+1])

        second_round = deque()

        # union people with people who know the truth
        # each party points the same parent node
        for _ in range(m):
            new = deque(map(int, input().split()))
            new.popleft()
            second_round.append(new)
            if len(new) < 2:
                continue

            for i in range(len(new) - 1):
                union(new[i], new[i+1])

        standard = find(truth[0])
        cnt = 0
        # comparison of parent nodes of each party
        # and parent nodes of people
        # who know the truth from the beginning
        for data in second_round:
            # different parent node == no one knows truth
            if find(data[0]) != standard:
                cnt += 1

        print(cnt)


