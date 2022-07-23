def floyd_warshall():
    global dist

    for transit in range(1, n+1):
        for start in range(1, n+1):
            for terminal in range(1, n+1):
                if start == terminal:
                    continue
                dist[start][terminal] = min(dist[start][transit] + dist[transit][terminal],
                                            dist[start][terminal])

    for start in range(1, n+1):
        for terminal in range(1, n+1):
            print(dist[start][terminal] if (dist[start][terminal] is not INF) else 0, end=" ")
        print()


if __name__ == '__main__':
    INF = 0x3f3f3f3f

    n = int(input())
    m = int(input())

    dist = [[INF]*(n+1) for _ in range(n+1)]

    for _ in range(m):
        u, v, w = map(int, input().split())
        dist[u][v] = min(dist[u][v], w)

    floyd_warshall()