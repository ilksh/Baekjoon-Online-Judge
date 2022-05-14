n = int(input())

word = []
for i in range(n):
    word.append(input())

# using 'set', avoid overlapping
word_set = list(set(word))

ans = []
for string in word_set:
    ans.append((len(string),string))

# sort the string in a short order
ans.sort()

for length, string in ans:
    print(string)

