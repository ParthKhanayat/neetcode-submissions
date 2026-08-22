class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<r)
        {
            int sum=nums[l]+nums[r];
            if(sum>target)
            {
                r--;
            }
            else if(sum<target)
            {
                l++;
            }
            else if(sum==target)
            {
                return {l+1,r+1}; //because the array is one indexed, weird ik
            }
        }
        return {0,0};
    }
};
