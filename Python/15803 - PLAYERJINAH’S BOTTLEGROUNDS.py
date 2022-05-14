import sys

coord = []
for _ in range(3):
    x, y = map(int, sys.stdin.readline().split())
    coord.append((x, y))

coord.sort()


def check():
    # There are three cases where three coordinates are on a straight line
    # Case 1: all x coordinates are the same
    if coord[0][0] == coord[1][0] == coord[2][0]:
        return True

    # Case 2: all y coordinates are the same
    if coord[0][1] == coord[1][1] == coord[2][1]:
        return True

    flag1 = False
    flag2 = False
    
    # Case 3: the slopes between the points are the same  
    if (coord[1][0] / coord[0][0]) == (coord[1][1] / coord[0][1]):
        flag1 = True
    if (coord[2][0] / coord[1][0]) == (coord[2][1] / coord[1][1]):
        flag2 = True

    if flag1 and flag2:
        return True

    return False


if check():
    print("WHERE IS MY CHICKEN?")

else:
    print("WINNER WINNER CHICKEN DINNER!")

