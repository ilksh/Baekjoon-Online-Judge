import sys
import heapq
input = sys.stdin.readline


def dijkstra(s, e):
    global dist, heap, route

    dist[s] = 0
    route[s].append(s)
    heapq.heappush(heap, (0, s))

    while heap:
        cur_weight, cur_node = heapq.heappop(heap)

        if dist[cur_node] < cur_weight:
            continue

        for edge in adj[cur_node]:
            next_weight, next_node = edge
            next_weight += cur_weight

            if next_weight < dist[next_node]:
                dist[next_node] = next_weight
                heapq.heappush(heap, (next_weight, next_node))
                route[next_node] = route[cur_node] + [next_node]

    return dist[e]


if __name__ == '__main__':
    INF = int(1e9)
    heap = []
    adj = {}

    n = int(input())    # number of city
    m = int(input())    # number of bus

    for i in range(n+1):
        adj[i] = []

    dist = [INF for _ in range(n+1)]
    route = [[] for _ in range(n+1)]

    for _ in range(m):
        node1, node2, weight = map(int, input().split())
        adj[node1].append((weight, node2))

    start, end = map(int, input().split())

    print(dijkstra(start, end))
    print(len(route[end]))

    for elem in route[end]:
        print(elem, end=" ")


