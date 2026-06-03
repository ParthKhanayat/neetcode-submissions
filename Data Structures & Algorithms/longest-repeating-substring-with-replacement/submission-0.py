class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count={} #hashmap for count
        l=0 #left pointer for sliding window
        maxLen=0
        for r in range(len(s)):
            count[s[r]]= 1 + count.get(s[r],0) #if s[r] does not exist then 0
            currLen=r-l+1
            #check if window is valid
            while currLen-max(count.values()) > k :
                count[s[l]]-=1
                l+=1
                currLen=r-l+1 #keep updating currLen as r and l are changing
            
            
            maxLen=max(maxLen,currLen)
        return maxLen
