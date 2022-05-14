import sys

n = int(sys.stdin.readline())
q = []

for _ in range(n):
    name, status = sys.stdin.readline().split()
    if status == 'enter':
        q.append(name)

    else:
        for i in range(len(q)):
            if q[i] == name:
                idx = i
                break
        q.pop(idx)

q.sort(reverse=True)
for ppl in q:
    print(ppl)


