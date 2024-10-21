class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        n = len(timeSeries)
        ans = 0  # Initialize ans
        for t in range(n):
            time = timeSeries[t]
            if(t+1<n): 
                e = timeSeries[t+1] - time
                ans += duration if e > duration else e
            else: 
                ans += duration
        return ans
