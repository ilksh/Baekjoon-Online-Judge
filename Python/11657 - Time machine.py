def bellman_ford(start):
    global dist, edge

    is_cycle = False
    dist = [INF for _ in range(n + 1)]
    dist[start] = 0

    for round in range(m):
        updated = False

        for e in edge:
            node1, node2, weight = e
            if dist[node1] is not INF and dist[node1] + weight < dist[node2]:
                dist[node2] = dist[node1] + weight
                updated = True

                if round == m - 1:
                    is_cycle = True

        if not updated:
            break

    return is_cycle


if __name__ == '__main__':
    INF = 0x3f3f3f3f3f3f3f3f
    edge = []
    dist = []

    n, m = map(int, input().split())

    for _ in range(m):
        u, v, w = map(int, input().split())
        edge.append((u, v, w))

    negative_cycle = bellman_ford(1)

    if negative_cycle:
        print(-1)
    else:
        for i in range(2, n + 1):
            print(dist[i] if (dist[i] is not INF) else -1)
