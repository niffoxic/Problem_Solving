class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        row = set()
        col = set()
        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                if matrix[r][c] == 0:
                    row.add(r)
                    col.add(c)
        for i in row:
            for j in range(len(matrix[0])):
                matrix[i][j] = 0
        for j in col:
            for r in range(len(matrix)):
                matrix[r][j] = 0
