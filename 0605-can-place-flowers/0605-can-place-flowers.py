class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        length = len(flowerbed)
        
        for i in range(length):
            if (flowerbed[i] == 0 and  # Check if current plot is empty
                (i == 0 or flowerbed[i - 1] == 0) and  # Check if it's the first plot or the previous plot is empty
                (i == length - 1 or flowerbed[i + 1] == 0)):  # Check if it's the last plot or the next plot is empty
                
                flowerbed[i] = 1  # Plant a flower here
                n -= 1  # Decrease the count of flowers to plant
                
                if n == 0:  # If no more flowers need to be planted
                    return True
        
        return n <= 0  # Check if all flowers have been planted