def valid(x, y):
    return 0 <= x < n and 0 <= y < m


def compute(x, y):
    counts = 0
    for _ in range(8):
        nx = dx[_] + x
        ny = dy[_] + y
        if valid(nx, ny) and arr[nx][ny] == '*':
            counts += 1
    return counts


n, m = map(int, input().split())
arr = list()
for i in range(n):
    arr += input().split()

dx = [0, 0, 1, -1, -1, 1, 1, -1]
dy = [1, -1, 0, 0, -1, 1, -1, 1]

res = True
for i in range(n):
    for j in range(m):
        if arr[i][j].isdigit() or arr[i][j] == '.':
            val = compute(i, j)
            if arr[i][j] == '.' and val:
                res = False
                break
            if arr[i][j].isdigit() and val != int(arr[i][j]):
                res = False
                break
    if not res:
        break

print("YES" if res else "NO")
