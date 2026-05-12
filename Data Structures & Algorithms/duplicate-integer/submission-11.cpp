class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> m1;
        for(int i=0;i<nums.size();i++)
        {
            if(m1.find(nums[i])!=m1.end())
            {
                return true;
            }
            m1.insert({nums[i],1});
        }
        return false;
    }
};