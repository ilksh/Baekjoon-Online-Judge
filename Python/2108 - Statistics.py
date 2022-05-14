import sys
import statistics
from collections import Counter

data = []
n = int(sys.stdin.readline())
for i in range(n):
    data.append(int(sys.stdin.readline()))

new_data = sorted(Counter(data).items(), key=lambda x: (-x[1],x[0]))

avg = round(statistics.mean(data))
med = statistics.median(data)


if n ==1:
    mode = data[0]

else:
    if new_data[0][1] == new_data[1][1]:
        mode = new_data[1][0]
    else:
        mode = new_data[0][0]

rng = max(data) - min(data)
print(avg)
print(med)
print(mode)
print(rng)
# n_data = Counter(data)
# Counter({1: 1, 6: 1, 8: 1, 3: 1, 9: 1})

