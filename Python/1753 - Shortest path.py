import heapq

def adj_check(u, v, w):
    global adj
    adj[u].append((w, v))

V, E = map(int, input().split())
start = int(input())

INF = int(1e9)
dist = [INF] * (V+1)

heap = []
adj = {}
for i in range(V):
    adj[i+1] = []

for _ in range(E):
    u, v, w = map(int, input().split())
    adj_check(u, v, w)

def dijkstra(start):
    dist[start] = 0
    heapq.heappush(heap, (0, start))

    while heap:
        cur_w, cur_node = heapq.heappop(heap)

        if dist[cur_node] < cur_w:
            continue

        for edge in adj[cur_node]:
            next_w, next_node = edge
            next_w += cur_w
            if next_w < dist[next_node]:
                dist[next_node] = next_w
                heapq.heappush(heap, (next_w, next_node))

dijkstra(start)

for i in range(1, V+1):
    if dist[i] != INF:
        print(dist[i])
    else:
        print("INF")

