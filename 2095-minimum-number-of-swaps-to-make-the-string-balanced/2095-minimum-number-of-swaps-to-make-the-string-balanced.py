class Solution:
    def minSwaps(self, s: str) -> int:
        stack = []
        unbalanced = 0
        for c in s:
            if c == '[':
                stack.append('[')
            else:
                if stack:
                    stack.pop()
                else:
                    unbalanced+=1
        return (unbalanced+1)//2
        