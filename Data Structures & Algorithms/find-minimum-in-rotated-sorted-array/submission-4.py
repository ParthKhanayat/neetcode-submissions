class Solution:
    def findMin(self, nums: List[int]) -> int:
        l,r=0,len(nums)-1
        res=nums[l]
        while l<=r :
            #when array is sorted
            if nums[l]<nums[r] :
                res=min(res,nums[l])
                break
            m=(l+r)//2
            res=min(res,nums[m])
            if nums[m]>=nums[l] : #this means we are in left sorted portion of array
                l=m+1 #search right
            else: #else we are in right sorted portion of array
                r=m-1 #search left
        return res
