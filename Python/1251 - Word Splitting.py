def reverse(string):
    string = string[::-1]
    return string


word = input()
length = len(word)
answer = []
void = ""

for i in range(1, length-1):
    for j in range(i+1, length):
        part1 = word[:i]
        part1 = reverse(part1)

        part2 = word[i:j]
        part2 = reverse(part2)

        part3 = word[j:]
        part3 = reverse(part3)

        answer.append(part1+part2+part3)

# print(answer)
answer = sorted(answer)
print(answer[0])




