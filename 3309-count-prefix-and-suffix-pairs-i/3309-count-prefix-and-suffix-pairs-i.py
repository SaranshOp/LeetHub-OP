class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        cnt = 0
        l = len(words)
        for i in range(l):
            for j in range(i, l):
                if i != j:
                    cnt += 1 if self.isPrefixAndSuffix(words[i], words[j]) else 0
        return cnt

    def isPrefixAndSuffix(self, str1: str, str2: str) -> bool:
        if len(str1) > len(str2):
            return False
        a = len(str1)
        if str1 == str2[:a] and str1 == str2[-a:]:
            return True
        return False
