import heapq

n = int(input())
array = []

for _ in range(n):
    num = list(map(int, input().split()))
    if not array:
        for elem in num:
            heapq.heappush(array, elem)

    else:
        for elem in num:
            # maintain the size of an array to n
            if array[0] < elem:
                heapq.heappush(array, elem)
                heapq.heappop(array)

print(array[0])
