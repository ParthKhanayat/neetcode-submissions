class Solution:
    def search(self, nums: List[int], target: int) -> int:
        #we will first find the min element(pivot) 
        #because min element is the starting of the right half

###############FIRST PASS(finding pivot)##########################################
        l,r=0,len(nums)-1
        if nums[l]==target : return l
        if nums[r]==target : return r
        minIdx=l
        while l<=r :
            if nums[l]<nums[r] : #sorted array
                if nums[l]<nums[minIdx] : minIdx=l #check and update which is min
                break
            m=(l+r)//2
            if nums[m]<nums[minIdx] : minIdx=m #check and update min
            if nums[m]>nums[r] : # we are in left half
                l=m+1
            else : # we are in right half
                r=m-1

####################SECOND PASS (finding target)##################################
        if nums[minIdx]==target : return minIdx
            #CONDITION 1 (Array is sorted fully)
        if minIdx==0 : #first element is min-> only possible if whole array is sorted
            l,r=0,len(nums)-1
            while l<=r:
                m=(r+l)//2
                if nums[m]==target : return m
                elif nums[m]>target :
                    r=m-1
                else:
                    l=m+1
            return -1
            #CONDITION 2: Target lies on the left side
        elif (target>nums[0]) and (target<=nums[minIdx-1]) :
            l,r=0,minIdx-1
            while l<=r:
                m=(r+l)//2
                if nums[m]==target : return m
                elif nums[m]>target :
                    r=m-1
                else:
                    l=m+1
            return -1
            #CONDITION 3: Target lies on the right side
        else:
            l,r=minIdx,len(nums)-1
            while l<=r:
                m=(r+l)//2
                if nums[m]==target : return m
                elif nums[m]>target :
                    r=m-1
                else:
                    l=m+1
            return -1
        return -1
