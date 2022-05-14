tc = int(input())

for _ in range(tc):
    s = input().lower()

    ans = []
    # Iterate from 'a' to 'z'
    for char in range(ord('a'), ord('z') + 1):
        cur = chr(char)
        # if s doesn't include current alphabet
        if s.find(cur) == -1:
            ans.append(cur)

    if ans:
        print("missing", end=" ")
        print("".join(ans))

    else:
        print("pangram")
