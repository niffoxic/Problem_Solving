# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        self.res = []
        def dfs(root, path, ts, target_sum):
            if not root: return 
            ts += root.val
            path.append(root.val)
            
            if root and not root.left and not root.right:
                if ts == target_sum:
                    self.res.append(path.copy())
            else:
                dfs(root.left, path, ts, target_sum)
                dfs(root.right, path, ts, target_sum)
            path.pop()
        dfs(root, [], 0, targetSum)
        return self.res
            
