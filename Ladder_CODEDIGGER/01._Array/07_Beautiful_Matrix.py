matrix = []
found = False
row = 0
col = 0
for i in range(5):
    matrix += [list(map(int, input().split()))]
    if 1 in matrix[i] and not found:
        row = i
        found = True
        for c in range(5):
            if matrix[row][c] == 1:
                col = c
                break
 
print(abs(2 - row) + abs(2 - col))
