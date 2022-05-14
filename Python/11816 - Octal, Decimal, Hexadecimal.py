n = input()

if n[0] == '0':
    if n[1] == 'x':
        print(int(n, 16))
    else:
        print(int(n, 8))
else:
    print(n)
