class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        queue = deque(senate)
        bans = 0
        while 'R' in queue and 'D' in queue:
            current = queue.popleft()
            if current == 'R':
                bans += 1
            else:
                bans -= 1
            if (current == 'D' and bans < 0) or (current == 'R' and bans > 0):
                queue.append(current)
        if queue[0] == 'D':
            return "Dire"
        return "Radiant"


            