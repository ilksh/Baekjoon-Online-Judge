import heapq
import sys
input = sys.stdin.readline


def adj_check(u, v, w):
    global adj
    adj[u].append((w, v))


def dijkstra(start, end):
    result = [INF for _ in range(n + 1)]

    result[start] = 0
    heapq.heappush(heap, (0, start))

    while heap:
        cur_w, cur_node = heapq.heappop(heap)

        if result[cur_node] < cur_w:
            continue

        for edge in adj[cur_node]:
            next_w, next_node = edge
            next_w += cur_w

            if next_w < result[next_node]:
                result[next_node] = next_w
                heapq.heappush(heap, (next_w, next_node))

    return result[end]


if __name__ == '__main__':
    INF = int(1e9)
    heap = []
    adj = {}
    ans = -1

    n, m, x = map(int, input().split())

    for i in range(n+1):
        adj[i] = []

    for _ in range(m):
        node1, node2, weight = map(int, input().split())
        adj_check(node1, node2, weight)

    for i in range(n):
        temp = dijkstra(i+1, x) + dijkstra(x, i+1)
        ans = max(ans, temp)

    print(ans)
