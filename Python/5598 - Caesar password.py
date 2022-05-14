string = input()

temp = ""
caesar = []

for char in string:
    num = ord(char)
    if num < 68:
        c = chr(num+23)
    else:
        c = chr(num - 3)

    caesar.append(c)

print(temp.join(caesar))
# ABCDEFGHIJKLNMOPQRSTUVWXYZ