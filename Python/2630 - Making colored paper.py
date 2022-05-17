n = int(input())

paper = [list(map(int, input().split())) for _ in range(n)]

white = 0
blue = 0


def solve(row, col, length):
    global white, blue

    standard = paper[row][col]
    for i in range(row, row+length):
        for j in range(col, col+length):
            # all element of current square is not identical
            # divide
            if paper[i][j] != standard:
                div = length//2
                solve(row, col, div)
                solve(row, col + div, div)
                solve(row+div, col, div)
                solve(row+div, col+div, div)
                return

    if standard == 0: white += 1
    else: blue += 1


solve(0, 0, n)
print(white)
print(blue)