def compute_quads(nx, ny):
    return 1 if x > y else 2 if y > x else 0


n = int(input())
moves = list(input())
x = 1 if moves[0] == 'R' else 0
y = 1 if moves[0] == 'U' else 0
quad, coins = compute_quads(x, y), 0
for i in range(1, n):
    x = x + 1 if moves[i] == 'R' else x
    y = y + 1 if moves[i] == 'U' else y
    if x != y:
        nq = compute_quads(x, y)
        if nq != quad:
            coins += 1
            quad = nq
print(coins)
