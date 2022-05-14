n, m = map(int, input().split())
dna = []

for _ in range(n):
    dna.append(input())

ans = []

for i in range(m):
    freq = {'A': 0, 'C': 0, 'G': 0, 'T': 0}
    mx = -1
    # Store the most frequently used alphabetical
    # frequency of A, C, G, and T for each digit.
    for j in range(n):
        cur = dna[j][i]
        freq[cur] += 1

    # Save the most used alphabet for each digit
    for key in freq.keys():
        if freq[key] > mx:
            mx = freq[key]
            mx_char = key
            
    ans.append(mx_char)

# Calculate Hamming Distance
cnt = 0
for i in range(m):
    for j in range(n):
        if dna[j][i] != ans[i]:
            cnt += 1
            continue

print("".join(ans))
print(cnt)

