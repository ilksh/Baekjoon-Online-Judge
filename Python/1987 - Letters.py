def out_of_boundary(y, x):
    global r, c
    if y >= r or y < 0 or x >= c or x < 0:
        return True

    return False


def dfs(row, col, cnt):
    global ans

    ans = max(ans, cnt)

    cur = board[row][col]
    visited[cur] = True

    for dir in range(4):
        nxt_row = row + dy[dir]
        nxt_col = col + dx[dir]

        if out_of_boundary(nxt_row, nxt_col):
            continue

        nxt = board[nxt_row][nxt_col]

        if not visited[nxt]:
            dfs(nxt_row, nxt_col, cnt+1)
            # backtracking
            visited[nxt] = False


if __name__ == '__main__':
    r, c = map(int, input().split())
    board = []
    visited = [False for _ in range(26)]

    # delta y, x
    dy = [0, 0, -1, 1]
    dx = [-1, 1, 0, 0]
    ans = -1

    # convert alphabet to integer for efficiency
    for _ in range(r):
        board.append(list(map(lambda a: ord(a) - 65, input())))

    dfs(0, 0, 1)
    print(ans)

"""
- the test case below shows why backtracking is required  rather than just dfs
- under the simple dfs, it is unable to search 'A' whose (row, col) is (0,2), (1,2), (2,2), (2,1), (2,0)
- since we already visited 'A' whose (row, col) is (0,1)

BAAK
CDAJ
AAAI
EFGH
"""
