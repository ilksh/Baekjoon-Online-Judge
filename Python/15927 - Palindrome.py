word = input()
front = word[0]

idt = True

# verify that all strings are identical
for char in word[1:]:
    if char != front:
        idt = False
        break

# all strings are identical
if idt:
    print(-1)

# all strings are not identical
# partial string exists
else:
    length = len(word)
    # check for circulation
    circle = True
    for i in range(length // 2):
        if word[i] != word[length - i - 1]:
            circle = False

    if circle:
        print(length - 1)
    else:
        print(length)