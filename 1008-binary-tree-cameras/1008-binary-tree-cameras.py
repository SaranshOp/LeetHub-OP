# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        covered = {None}
        self.ans = 0
        def dfs(node, par = None): 
            if (node == None): 
                return
            else:
                dfs(node.left, node)
                dfs(node.right, node)
            
            print(" -> ")
            print(" this node is ")
            if( (par is None and node not in covered) or (node.left not in covered or node.right not in covered)):
                self.ans += 1
                covered.update({node, par, node.left, node.right})
                print("added")
            
        dfs(root)
        if self.ans == 0:
            self.ans += 1
        return self.ans