class Solution:

    def __init__(self):
        self.visited = None
        self.width = None
        self.height = None
        self.grid = None

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.grid = grid
        self.height = len(self.grid)
        self.width = len(self.grid[0])
        self.visited = [[0 for _ in range(self.width)] for _ in range(self.height)]
        res = 0

        for x in range(self.height):
            for y in range(self.width):
                res = max(res, self.dfs(x, y))

        return res

    def dfs(self, x, y):
        if x < 0 or y < 0 or x >= self.height or y >= self.width or self.grid[x][y] == 0:
            return 0
        elif self.visited[x][y] == 0 and self.grid[x][y] == 1:
            self.visited[x][y] = 1
            return 1 + sum(
                [self.dfs(x + nx, y + ny) for (nx, ny) in [(1, 0), (-1, 0), (0, 1), (0, -1)]])
        else:
            return 0
