from itertools import combinations

# consonants
cons = ['a', 'e', 'i', 'o', 'u']

l, c = map(int, input().split())
char = list(input().split())
char.sort()

pw = list(combinations(char, l))

ans = []

for word in pw:
    cons_cnt = 0
    for i in word:
        if i in cons:
            cons_cnt += 1
    # when word includes at least one consonant
    # and includes vowel (l-cons_cnt) at least 2
    if cons_cnt > 0 and (l-cons_cnt) >= 2:
        ans.append("".join(word))

for data in ans:
    print(data)






