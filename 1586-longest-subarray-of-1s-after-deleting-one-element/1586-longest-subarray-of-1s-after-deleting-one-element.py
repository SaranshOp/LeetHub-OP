class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        lastzIndex=-1
        left=0
        right=0
        count=0
        for i in range(len(nums)):
            if(nums[i]==0):
                left = lastzIndex+1
                lastzIndex = i
            right = i
            count = max(count, right-
            left+1)
        return count -1
        