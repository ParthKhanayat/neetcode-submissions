class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        int prefix=1;
        for(int i=0;i<nums.size();i++)
        {
            res[i]=prefix;
            prefix=prefix*nums[i];
        }
        int postfix=1;
        for(int j=nums.size()-1;j>=0;j--)
        {
            res[j]=res[j]*postfix;
            postfix=postfix*nums[j];
        }

        return res;
    }
};
