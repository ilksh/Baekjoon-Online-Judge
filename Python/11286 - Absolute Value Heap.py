import sys
import heapq

input = sys.stdin.readline

tc = int(input())
heap = []

for _ in range(tc):
    data = int(input())
    if data == 0:
        if heap:
            print(heapq.heappop(heap)[1])
        else:
            print(0)
    else:
        heapq.heappush(heap, [abs(data), data])
