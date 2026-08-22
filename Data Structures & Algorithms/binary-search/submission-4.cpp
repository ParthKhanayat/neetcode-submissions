class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(target>nums[m])
            {
                l=m+1;
            }
            else if(target<nums[m])
            {
                h=m-1;
            }
            else if(target==nums[m])
            {
                return m;
            }
        }
        return -1;
    }
};
