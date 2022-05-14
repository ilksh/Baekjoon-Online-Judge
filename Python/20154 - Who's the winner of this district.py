word = {
    'A': 3, 'B': 2, 'C': 1, 'D': 2, 'E': 3, 'F': 3, 'G': 3, 'H': 3, 'I': 1,
    'J': 1, 'K': 3, 'L': 1, 'M': 3, 'N': 3, 'O': 1, 'P': 2, 'Q': 2, 'R': 2,
    'S': 1, 'T': 2, 'U': 1, 'V': 1, 'W': 2, 'X': 2, 'Y': 2, 'Z': 1,
}

string = input()
ans = 0

for char in string:
    # alphabet = key, temp = value
    ans += word[char]
    ans %= 10

    for alphabet, temp in word.items():
        if alphabet == char:
            ans += temp
            if ans > 10:
                ans %= 10

if ans % 2 == 0:
    print("You're the winner?")

else:
    print("I'm a winner!")