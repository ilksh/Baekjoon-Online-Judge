import heapq
import sys
input = sys.stdin.readline


def _4485(n) :
    q = []
    heapq.heappush(q,(0, 0, g[0][0]))
    INF = int(1e9)
    move = [[-1,0], [0, -1], [0, 1], [1, 0]]
    visited = [[INF] * n for i in range(n)]

    while q :
        x, y, dis = heapq.heappop(q)

        if visited[x][y] < dis :
            continue

        for i in range(4):
            nx, ny = move[i][0] + x, move[i][1] + y
            if nx < 0 or ny < 0 or nx >= n or ny >= n :
                continue

            cost = g[nx][ny] + dis

            if cost < visited[nx][ny] :
                visited[nx][ny] = cost
                heapq.heappush(q,(nx,ny,cost))
    return visited

cnt = 0
while True :
    g = []
    n = int(input())
    cnt += 1

    if n == 0 :
        break

    for i in range(n) :
        g.append(list(map(int, input().split())))

    print("Problem {0}: {1}".format(cnt, _4485(n)[n-1][n-1]))
