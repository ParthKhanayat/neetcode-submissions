class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2,0);
        
        for(int i=0;i<nums.size();i++)
        {   
            for(int j=nums.size()-1;j>i;j--)
            {
                
                if(target==nums[i]+nums[j])
                {
                    res[0]=i;
                    res[1]=j;
                    return res;
                }
            }
            
            
        }
        return res;
    }
};
