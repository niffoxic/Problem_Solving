class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i, j in enumerate(board):
            if len([x for x in j if x != '.']) != len(set([x for x in j if x != '.'])):
                return False
            if len([x[i] for x in board if x[i] != '.']) != len(set([x[i] for x in board if x[i] != '.'])):
                return False
        for i in (0, 3, 6):
            for j in (0, 3, 6):
                res = [board[x][y] for x in range(i, i + 3) for y in range(j, j + 3)]

                if len([x for x in res if x != '.']) != len(set([x for x in res if x != '.'])):
                    return False
        return True
