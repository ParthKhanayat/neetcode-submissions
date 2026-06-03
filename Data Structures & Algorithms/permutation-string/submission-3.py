class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # s1- pattern
        # s2- text
        # permutation: anagram
        # edge case:
        if len(s1) > len(s2):
            return False

        patternFreq = dict(Counter(s1))
        windowFreq = dict(Counter(s2[: len(s1)]))
        l = 0
        r = l + len(s1)
        while r <= len(s2):
            if patternFreq == windowFreq:
                return True
            elif r == len(s2):
                return False
            windowFreq[s2[l]] -= 1
            if windowFreq[s2[l]] == 0:
                del windowFreq[s2[l]] #when a count becomes 0 (eg: c:0), python still keeps it, while comparing both not having c in dict and c:0 are two different things hence it gives false, therefore we remove it
            l += 1
            windowFreq[s2[r]] = 1 + windowFreq.get(s2[r], 0)  # 0 if does not exist
            r += 1
        return False
