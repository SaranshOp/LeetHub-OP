class Solution:
    def dfs(self,n,k,rootVal):
        if(n == 1):
            return rootVal
        totN = 2**(n-1)
        if(k > totN / 2):
            nextVal = 1 if (rootVal == 0) else 0
            return self.dfs(n-1, k - (totN/2), nextVal)
        else:
            nextVal = 0 if (rootVal == 0) else 1
            return self.dfs(n-1, k, nextVal)
        
    def kthGrammar(self, n: int, k: int) -> int:
        return self.dfs(n,k,0)
        