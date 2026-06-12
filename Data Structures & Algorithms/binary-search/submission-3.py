class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l,h=0,len(nums)-1
        #note: list is already sorted 
        while l<=h :
            m=(l+h)//2 #in languages other than python, integer overflow can happen, to prevent that use a different approcah to find midpoint l+((r-l)//2) : l+half the distance b/w l and r
            if nums[m]==target :
                return m
            elif nums[m]<target :
                l=m+1 #m is not target so we must start search after m
            elif nums[m]>target :
                h=m-1 #m is not target so we must stop before m
        return -1
