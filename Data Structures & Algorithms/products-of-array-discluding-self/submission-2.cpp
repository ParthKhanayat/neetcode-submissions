class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        int prefix=1; //for the leftmost(fisrt) element, the prefix is 1 by default
        for(int i=0;i<nums.size();i++)
        {
            res[i]=prefix;
            prefix*=nums[i];
        }
        int postfix=1; //for the leftmost(last) element, the prefix is 1 by default
        for(int i=nums.size()-1;i>=0;i--)
        {
            res[i]*=postfix;
            postfix*=nums[i];
        }
        return res;
        //pretty easy 😀 after understanding

    }
};
