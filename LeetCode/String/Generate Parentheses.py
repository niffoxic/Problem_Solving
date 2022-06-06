class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = [set() for _ in range(n + 1)]
        res[0].add('')
        for i in range(1, n + 1):
            res[i].update(f'({j})' for j in res[i - 1])
            for j in range(1, i):
                res[i].update(f'{k}{r}' for k in res[j] for r in res[i - j])
        return sorted(list(res[n]))
